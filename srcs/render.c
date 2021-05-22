/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeong <seujeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 21:04:08 by hyeojang          #+#    #+#             */
/*   Updated: 2021/05/22 21:00:29 by seujeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	render_fc(t_info *info)
{
	int	x;
	int	y;

	x = -1;
	while (++x < info->img.width)
	{
		y = -1;
		while (++y < info->img.height)
		{
			info->img.data[y * info->img.width + x] = info->color[0].c;
			info->img.data[(info->img.height - y - 1) *
			info->img.width + x] = info->color[1].c;
		}
	}
}

void	render_init(t_info *info, int x)
{
	float	camera;

	camera = (2 * x / (float)(info->img.width)) - 1;
	info->ray.x = info->dir.x + info->plane.x * camera;
	info->ray.y = info->dir.y + info->plane.y * camera;
	info->mapxy.x = (int)(info->pos.x);
	info->mapxy.y = (int)(info->pos.y);
	info->deltadist.x = fabs(1 / info->ray.x);
	info->deltadist.y = fabs(1 / info->ray.y);
}

void	render_wall(t_info *info)
{
	int		x;
	int		texnum;
	int		tex_x;

	x = 0;
	while (x < info->img.width)
	{
		render_init(info, x);
		render_raydir(info);
		render_hit(info);
		texnum = render_texnum(info);
		tex_x = render_len(info, texnum);
		render_draw(info, texnum, tex_x, x);
		info->buf[x] = info->walldist;
		x++;
	}
}

void	render(t_info *info)
{
	render_fc(info);
	render_wall(info);
	render_sprite(info);
}
