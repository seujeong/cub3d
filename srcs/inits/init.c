/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeong <seujeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 19:23:10 by sanoh             #+#    #+#             */
/*   Updated: 2021/05/22 20:58:02 by seujeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	init_sprite_pos(t_info *info)
{
	int	x;
	int	y;
	int i;

	i = 0;
	y = -1;
	info->sprite.spos = malloc(sizeof(t_sprite) * info->sprite.snum);
	while (++y < info->map.height)
	{
		x = -1;
		while (++x < info->map.width)
		{
			if (info->map.data[y][x] > 49)
			{
				info->sprite.spos[i].x = x + 0.5;
				info->sprite.spos[i].y = y + 0.5;
				info->sprite.spos[i].n = info->map.data[y][x];
				i++;
			}
		}
	}
}

void	init_struct(t_info *info)
{
	int	i;

	i = -1;
	while (++i < 5)
		info->tex[i].img = 0;
	info->key.left = 0;
	info->key.right = 0;
	info->sprite.snum = 0;
	info->ptype.map = 0;
	info->ptype.check = 1;
}

void	init(t_info *info, int flag, char *av)
{
	init_struct(info);
	info->mlx = mlx_init();
	mlx_get_screen_size(info->mlx, &info->img.width, &info->img.height);
	init_parse(info, av);
	info->ptype.check_exit = 3;
	info->buf = (float *)malloc(sizeof(float) * info->img.width);
	init_sprite_pos(info);
	if (!flag)
		info->win = mlx_new_window(info->mlx,
			info->img.width, info->img.height, "살려줘!!!");
	info->img.img = mlx_new_image(info->mlx,
		info->img.width, info->img.height);
	info->img.data = (int *)mlx_get_data_addr(info->img.img,
		&info->img.bpp, &info->img.line_length, &info->img.endian);
	info->ptype.check_exit = 4;
}
