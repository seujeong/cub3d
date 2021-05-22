/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeong <seujeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 19:23:01 by sanoh             #+#    #+#             */
/*   Updated: 2021/05/22 21:40:56 by seujeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	parse_texture(t_info *info, int type, char *path)
{
	t_img	*image;

	info->ptype.check_exit = 1;
	image = &info->tex[type];
	if (!(image->img = mlx_xpm_file_to_image(info->mlx,
	path, &image->width, &image->height)))
		exit_msg(info, "texture");
	if (!(image->data = (int *)mlx_get_data_addr(image->img,
	&image->bpp, &image->line_length, &image->endian)))
		exit_msg(info, "texture");
	check_parse(info, type);
}
