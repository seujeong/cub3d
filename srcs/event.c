/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeong <seujeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 19:27:20 by sanoh             #+#    #+#             */
/*   Updated: 2021/05/22 21:00:08 by seujeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	key_press(int keycode, t_info *info)
{
	if (keycode == KEY_W)
		info->key.w = 1;
	if (keycode == KEY_A)
		info->key.a = 1;
	if (keycode == KEY_S)
		info->key.s = 1;
	if (keycode == KEY_D)
		info->key.d = 1;
	if (keycode == KEY_LEFT)
		info->key.left = 1;
	if (keycode == KEY_RIGHT)
		info->key.right = 1;
	if (keycode == KEY_ESC)
		exit_cub3d(info, 1);
	return (0);
}

int	key_release(int keycode, t_info *info)
{
	if (keycode == KEY_W)
		info->key.w = 0;
	if (keycode == KEY_A)
		info->key.a = 0;
	if (keycode == KEY_S)
		info->key.s = 0;
	if (keycode == KEY_D)
		info->key.d = 0;
	if (keycode == KEY_LEFT)
		info->key.left = 0;
	if (keycode == KEY_RIGHT)
		info->key.right = 0;
	return (0);
}

int	exit_hook(t_info *info)
{
	exit_cub3d(info, 0);
	return (0);
}
