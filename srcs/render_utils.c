/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeong <seujeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 03:10:18 by hyeojang          #+#    #+#             */
/*   Updated: 2021/05/22 21:00:26 by seujeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	render_raydir(t_info *info)
{
	if (info->ray.x < 0)
	{
		info->step.x = -1;
		info->sidedist.x = (info->pos.x - info->mapxy.x) * info->deltadist.x;
	}
	else
	{
		info->step.x = 1;
		info->sidedist.x = (info->mapxy.x + 1.0 - info->pos.x) *
		info->deltadist.x;
	}
	if (info->ray.y < 0)
	{
		info->step.y = -1;
		info->sidedist.y = (info->pos.y - info->mapxy.y) * info->deltadist.y;
	}
	else
	{
		info->step.y = 1;
		info->sidedist.y = (info->mapxy.y + 1.0 - info->pos.y) *
		info->deltadist.y;
	}
}

void	render_hit(t_info *info)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (info->sidedist.x < info->sidedist.y)
		{
			info->sidedist.x += info->deltadist.x;
			info->mapxy.x += info->step.x;
			info->side = 0;
		}
		else
		{
			info->sidedist.y += info->deltadist.y;
			info->mapxy.y += info->step.y;
			info->side = 1;
		}
		if (info->map.data[info->mapxy.y][info->mapxy.x] == 49)
			hit = 1;
	}
}

int		render_texnum(t_info *info)
{
	if (info->side == 0)
		info->walldist =
		(info->mapxy.x - info->pos.x + (1 - info->step.x) / 2) / info->ray.x;
	else
		info->walldist =
		(info->mapxy.y - info->pos.y + (1 - info->step.y) / 2) / info->ray.y;
	info->lineh = (int)(info->img.height / info->walldist);
	info->drawstart = (-info->lineh / 2) + (info->img.height / 2);
	if (info->drawstart < 0)
		info->drawstart = 0;
	info->drawend = (info->lineh / 2) + (info->img.height / 2);
	if (info->drawend >= info->img.height)
		info->drawend = info->img.height - 1;
	if (info->side == 1 && info->mapxy.y > info->pos.y)
		return (SO);
	else if (info->side == 1 && info->mapxy.y < info->pos.y)
		return (NO);
	else if (info->side == 0 && info->mapxy.x > info->pos.x)
		return (EA);
	return (WE);
}

int		render_len(t_info *info, int texnum)
{
	float	wall_x;
	int		tex_x;

	if (info->side == 0)
		wall_x = info->pos.y + info->walldist * info->ray.y;
	else
		wall_x = info->pos.x + info->walldist * info->ray.x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (float)info->tex[texnum].width);
	if (info->side == 0 && info->ray.x < 0)
		tex_x = info->tex[texnum].width - tex_x - 1;
	if (info->side == 1 && info->ray.y > 0)
		tex_x = info->tex[texnum].width - tex_x - 1;
	return (tex_x);
}

void	render_draw(t_info *info, int texnum, int tex_x, int x)
{
	float	step;
	float	texpos;
	int		color;
	int		tex_y;
	int		y;

	y = info->drawstart - 1;
	step = 1.0 * info->tex[texnum].height / info->lineh;
	texpos = (info->drawstart - info->img.height / 2 + info->lineh / 2) * step;
	while (++y < info->drawend)
	{
		tex_y = (int)texpos & (info->tex[texnum].height - 1);
		texpos += step;
		color = info->tex[texnum].data[info->tex[texnum].height *
		tex_y + tex_x];
		if (info->side == 1)
			color = (color >> 1) & 8355711;
		info->img.data[y * info->img.width + x] = color;
	}
}
