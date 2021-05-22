/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeong <seujeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 19:28:05 by sanoh             #+#    #+#             */
/*   Updated: 2021/05/22 21:49:22 by seujeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		main_loop(t_info *info)
{
	move(info);
	render(info);
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
	mlx_do_sync(info->mlx);
	return (0);
}

int		main(int ac, char **av)
{
	t_info	info;
	int		flag;

	info.ptype.check_exit = 0;
	flag = (ac == 3 && !ft_strcmp(av[2], "--save"));
	if (ac != 2 + flag)
		exit_msg(&info, "show me the map!");
	init(&info, flag, av[1]);
	if (flag)
		return (save(&info));
	mlx_hook(info.win, X_KEY_PRESS, 0, key_press, &info);
	mlx_hook(info.win, X_KEY_RELEASE, 0, key_release, &info);
	mlx_hook(info.win, X_EXIT, 0, exit_hook, &info);
	mlx_loop_hook(info.mlx, main_loop, &info);
	mlx_loop(info.mlx);
	return (0);
}
