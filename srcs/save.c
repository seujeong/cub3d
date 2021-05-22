/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeong <seujeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:27:23 by hyeojang          #+#    #+#             */
/*   Updated: 2021/05/22 21:00:33 by seujeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	bmp_header(t_info *info, int fd, int tmp)
{
	write(fd, "BM", 2);
	tmp = 14 + 40 + 4 * info->img.width * info->img.height;
	write(fd, &tmp, 4);
	tmp = 0;
	write(fd, &tmp, 2);
	write(fd, &tmp, 2);
	tmp = 54;
	write(fd, &tmp, 4);
	tmp = 40;
	write(fd, &tmp, 4);
	write(fd, &info->img.width, 4);
	write(fd, &info->img.height, 4);
	tmp = 1;
	write(fd, &tmp, 2);
	write(fd, &info->img.bpp, 2);
	tmp = 0;
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
}

static void	bmp_data(t_info *info, int fd)
{
	int		x;
	int		y;

	y = info->img.height;
	while (y-- > 0)
	{
		x = -1;
		while (++x < info->img.width)
			write(fd, &info->img.data[y * info->img.line_length / 4 + x], 4);
	}
	system("chmod 777 image.bmp");
}

int			save(t_info *info)
{
	int		fd;
	int		tmp;

	tmp = 0;
	if ((fd = open("./image.bmp", O_RDWR | O_CREAT)) == -1)
		exit_msg(info, "image.bmp file");
	move(info);
	render(info);
	bmp_header(info, fd, tmp);
	bmp_data(info, fd);
	close(fd);
	return (0);
}
