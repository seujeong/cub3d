/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeong <seujeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 19:28:00 by sanoh             #+#    #+#             */
/*   Updated: 2021/05/22 21:00:11 by seujeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	free_all(void *target)
{
	if (target)
		free(target);
}

void		exit_cub3d(t_info *info, int check)
{
	int	i;

	i = -1;
	if (info->ptype.check_exit)
	{
		if (info->ptype.check_exit > 0)
			while (++i < 5)
				if (info->tex[i].img)
					mlx_destroy_image(info->mlx, info->tex[i].img);
		i = -1;
		if (info->ptype.check_exit > 1)
			while (++i < info->map.height)
				free_all(info->map.data[i]);
		if (info->ptype.check_exit > 2)
			free_all(info->sprite.spos);
		if (info->ptype.check_exit > 2)
			free_all(info->buf);
		if (info->ptype.check_exit > 3)
			mlx_destroy_image(info->mlx, info->img.img);
		if (info->ptype.check_exit > 3)
			mlx_destroy_window(info->mlx, info->win);
	}
	exit(check);
}

int			exit_msg(t_info *info, char const *msg)
{
	write(1, "ERROR\n", 6);
	write(1, msg, ft_strlen(msg));
	write(1, "\n", 1);
	exit_cub3d(info, 1);
	return (0);
}
