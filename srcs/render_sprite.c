/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeong <seujeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 19:28:34 by sanoh             #+#    #+#             */
/*   Updated: 2021/05/22 21:00:24 by seujeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	compare_spos(t_spos i, t_spos j, t_info *info)
{
	float	ix;
	float	iy;
	float	jx;
	float	jy;

	ix = (fabs)(i.x - info->pos.x);
	iy = (fabs)(i.y - info->pos.y);
	jx = (fabs)(j.x - info->pos.x);
	jy = (fabs)(j.y - info->pos.y);
	if (((ix * ix) + (iy * iy)) < ((jx * jx) + (jy * jy)))
		return (1);
	return (0);
}

static void	sortsprites(t_info *info)
{
	int		i;
	int		j;
	t_spos	s;

	i = -1;
	while (++i < info->sprite.snum - 1)
	{
		j = i;
		while (++j < info->sprite.snum)
		{
			if (compare_spos(info->sprite.spos[i], info->sprite.spos[j], info))
			{
				s = info->sprite.spos[i];
				info->sprite.spos[i] = info->sprite.spos[j];
				info->sprite.spos[j] = s;
			}
		}
	}
}

void		draw_sprite(t_info *info, int stripe, t_sprite *s)
{
	int			texx;
	int			texy;
	int			d;
	int			y;

	texx = (int)(256 * (stripe - (-s->spritewidth / 2 + s->spritescreenx)) *
	info->tex[4].width / s->spritewidth) / 256;
	if (s->transformy > 0 && stripe > 0 && stripe < info->img.width &&
	s->transformy < info->buf[stripe])
	{
		y = s->drawstarty;
		while (y < s->drawendy)
		{
			d = (y) * 256 - info->img.height * 128 + s->spriteheight * 128;
			texy = ((d * info->tex[4].height) / s->spriteheight) / 256;
			s->color = info->tex[4].data[info->tex[4].height * texy + texx];
			if ((s->color & 0x00FFFFFF) != 0)
				info->img.data[y * info->img.width + stripe] = s->color;
			y++;
		}
	}
}

void		init_sprite(t_info *info, t_sprite *s)
{
	s->invdet =
	1.0 / (info->plane.x * info->dir.y - info->dir.x * info->plane.y);
	s->transformx =
	s->invdet * (info->dir.y * s->spritex - info->dir.x * s->spritey);
	s->transformy =
	s->invdet * (-info->plane.y * s->spritex + info->plane.x * s->spritey);
	s->spritescreenx =
	(int)((info->img.width / 2) * (1 + s->transformx / s->transformy));
	s->spriteheight = fabs(info->img.height / (s->transformy));
	s->drawstarty = -s->spriteheight / 2 + info->img.height / 2;
	if (s->drawstarty < 0)
		s->drawstarty = 0;
	s->drawendy = s->spriteheight / 2 + info->img.height / 2;
	if (s->drawendy >= info->img.height)
		s->drawendy = info->img.height - 1;
	s->spritewidth = fabs(info->img.height / (s->transformy));
	s->drawstartx = -s->spritewidth / 2 + s->spritescreenx;
	if (s->drawstartx < 0)
		s->drawstartx = 0;
	s->drawendx = s->spritewidth / 2 + s->spritescreenx;
	if (s->drawendx >= info->img.width)
		s->drawendx = info->img.width - 1;
}

void		render_sprite(t_info *info)
{
	int	i;
	int	stripe;

	i = -1;
	sortsprites(info);
	while (++i < info->sprite.snum)
	{
		info->sprite.spritex = info->sprite.spos[i].x - info->pos.x;
		info->sprite.spritey = info->sprite.spos[i].y - info->pos.y;
		init_sprite(info, &info->sprite);
		stripe = info->sprite.drawstartx;
		while (stripe < info->sprite.drawendx)
		{
			draw_sprite(info, stripe, &info->sprite);
			stripe++;
		}
	}
}
