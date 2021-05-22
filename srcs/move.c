/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeong <seujeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 19:28:24 by sanoh             #+#    #+#             */
/*   Updated: 2021/05/22 21:00:20 by seujeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		move_lr(t_info *info)
{
	float	olddir_x;
	float	oldp_x;

	olddir_x = info->dir.x;
	oldp_x = info->plane.x;
	if (info->key.left == 0 && info->key.right == 1)
	{
		info->dir.x = info->dir.x * cos(RSPEED) - info->dir.y * sin(RSPEED);
		info->dir.y = olddir_x * sin(RSPEED) + info->dir.y * cos(RSPEED);
		info->plane.x =
		info->plane.x * cos(RSPEED) - info->plane.y * sin(RSPEED);
		info->plane.y = oldp_x * sin(RSPEED) + info->plane.y * cos(RSPEED);
	}
	if (info->key.right == 0 && info->key.left == 1)
	{
		info->dir.x = info->dir.x * cos(-RSPEED) - info->dir.y * sin(-RSPEED);
		info->dir.y = olddir_x * sin(-RSPEED) + info->dir.y * cos(-RSPEED);
		info->plane.x =
		info->plane.x * cos(-RSPEED) - info->plane.y * sin(-RSPEED);
		info->plane.y = oldp_x * sin(-RSPEED) + info->plane.y * cos(-RSPEED);
	}
}

void		move_ad(t_info *info)
{
	if (info->key.a == 1)
	{
		if ('1' != info->map.data[(int)(info->pos.y)]
		[(int)(info->pos.x + info->dir.y * MSPEED)])
			info->pos.x += info->dir.y * MSPEED;
		if ('1' != info->map.data[(int)(info->pos.y - info->dir.x * MSPEED)]
		[(int)(info->pos.x)])
			info->pos.y -= info->dir.x * MSPEED;
	}
	if (info->key.d == 1)
	{
		if ('1' != info->map.data[(int)(info->pos.y)]
		[(int)(info->pos.x - info->dir.y * MSPEED)])
			info->pos.x -= info->dir.y * MSPEED;
		if ('1' != info->map.data[(int)(info->pos.y + info->dir.x * MSPEED)]
		[(int)(info->pos.x)])
			info->pos.y += info->dir.x * MSPEED;
	}
}

void		move_ws(t_info *info)
{
	if (info->key.w == 1)
	{
		if ('1' != info->map.data[(int)(info->pos.y)]
		[(int)(info->pos.x + info->dir.x * MSPEED)])
			info->pos.x += info->dir.x * MSPEED;
		if ('1' != info->map.data[(int)(info->pos.y + info->dir.y * MSPEED)]
		[(int)(info->pos.x)])
			info->pos.y += info->dir.y * MSPEED;
	}
	if (info->key.s == 1)
	{
		if ('1' != info->map.data[(int)(info->pos.y)]
		[(int)(info->pos.x - info->dir.x * MSPEED)])
			info->pos.x -= info->dir.x * MSPEED;
		if ('1' != info->map.data[(int)(info->pos.y - info->dir.y * MSPEED)]
		[(int)(info->pos.x)])
			info->pos.y -= info->dir.y * MSPEED;
	}
}

void		move(t_info *info)
{
	move_ws(info);
	move_ad(info);
	move_lr(info);
}
