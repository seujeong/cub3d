#include "cub3d.h"

t_pos		cast_hor_ray(t_game *game, t_config c, t_ray *r, double angle)
{
	t_pos	win;
	t_pos	intercept;
	t_pos	tocheck;
	t_pos	step;
	t_pos	next;

	intercept.y = floor(game->player.y / c.tile) * c.tile;
	intercept.y += r->isdown ? c.tile : 0;
	intercept.x = game->player.x + (intercept.y - game->player.y) / tan(angle);
	set_pos(&step, c.tile / tan(angle), c.tile * (r->isup ? -1 : 1));
	(r->isleft && step.x > 0) || (r->isright && step.x < 0) ? step.x *= -1 : 0;
	set_pos(&next, intercept.x, intercept.y);
	while (next.x > 0 && next.x < c.width && next.y > 0 && next.y < c.height)
	{
		set_pos(&tocheck, next.x, next.y + (r->isup ? -1 : 0));
		if (is_sprite(tocheck.x, tocheck.y, game) &&
				!r->sprite.horhit.x && !r->sprite.horhit.y)
			copy_pos(&r->sprite.horhit, &tocheck);
		if (is_wall(tocheck.x, tocheck.y, game))
			return (next);
		set_pos(&next, next.x + step.x, next.y + step.y);
	}
	set_pos(&win, c.width, c.height);
	restrain_pos(&next, &win);
	return (next);
}

t_pos		cast_ver_ray(t_game *game, t_config c, t_ray *r, double angle)
{
	t_pos	win;
	t_pos	intercept;
	t_pos	tocheck;
	t_pos	step;
	t_pos	next;

	intercept.x = floor(game->player.x / c.tile) * c.tile;
	intercept.x += r->isright ? c.tile : 0;
	intercept.y = game->player.y + (intercept.x - game->player.x) * tan(angle);
	set_pos(&step, c.tile * (r->isleft ? -1 : 1), c.tile * tan(angle));
	step.y *= ((r->isup && step.y > 0) || (r->isdown && step.y < 0)) ? -1 : 1;
	set_pos(&next, intercept.x, intercept.y);
	while (next.x > 0 && next.x < c.width && next.y > 0 && next.y < c.height)
	{
		set_pos(&tocheck, next.x + (r->isleft ? -1 : 0), next.y);
		if (is_sprite(tocheck.x, tocheck.y, game) &&
				!r->sprite.verhit.x && !r->sprite.verhit.y)
			copy_pos(&r->sprite.verhit, &tocheck);
		if (is_wall(tocheck.x, tocheck.y, game))
			return (next);
		set_pos(&next, next.x + step.x, next.y + step.y);
	}
	set_pos(&win, c.width, c.height);
	restrain_pos(&next, &win);
	return (next);
}

static int	find_wall_hit_content(t_ray *r)
{
	if (r->isdown && !r->washitvertical)
		return (C_NO);
	else if (r->isup && !r->washitvertical)
		return (C_SO);
	else if (r->isleft && r->washitvertical)
		return (C_EA);
	else
		return (C_WE);
}

static void	check_ray_direction(t_ray *ray, double rayangle)
{
	ray->rayangle = rayangle;
	ray->isdown = rayangle > 0 && rayangle < M_PI;
	ray->isup = !ray->isdown;
	ray->isright = rayangle < (M_PI / 2) || rayangle > 1.5 * M_PI;
	ray->isleft = !ray->isright;
}

void		cast_a_ray(t_game *game, t_ray *ray, double rayangle)
{
	t_pos	horhit;
	t_pos	verhit;
	double	hordist;
	double	verdist;

	rayangle = normalize_angle(rayangle);
	check_ray_direction(ray, rayangle);
	horhit = cast_hor_ray(game, game->config, ray, rayangle);
	verhit = cast_ver_ray(game, game->config, ray, rayangle);
	hordist = hypot(game->player.x - horhit.x, game->player.y - horhit.y);
	verdist = hypot(game->player.x - verhit.x, game->player.y - verhit.y);
	if (verdist < hordist)
	{
		ray->distance = verdist * cos(rayangle - game->player.rotationangle);
		ray->wallhit = verhit;
		ray->washitvertical = TRUE;
	}
	else
	{
		ray->distance = hordist * cos(rayangle - game->player.rotationangle);
		ray->wallhit = horhit;
		ray->washitvertical = FALSE;
	}
	ray->wallhitcontent = find_wall_hit_content(ray);
}
