/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeong <seujeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 19:22:39 by sanoh             #+#    #+#             */
/*   Updated: 2021/05/22 23:04:08 by seujeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	check_map(t_info *info, int x, int y)
{
	t_map	*cmap;

	cmap = &info->map;
	if (!ft_strchr(" 012NSWE", cmap->data[y][x]) ||
		((y == 0 || x == 0 || y == cmap->height - 1 || x == cmap->width - 1) &&
		!ft_strchr(" 1", cmap->data[y][x])))
		exit_msg(info, "map");
	if (cmap->data[y][x] == ' ')
	{
		if ((y != 0 && !ft_strchr(" 1", cmap->data[y - 1][x])) ||
			(x != 0 && !ft_strchr(" 1", cmap->data[y][x - 1])) ||
			(y < cmap->height - 1 && !ft_strchr(" 1", cmap->data[y + 1][x])) ||
			(x < cmap->width - 1 && !ft_strchr(" 1", cmap->data[y][x + 1])))
			exit_msg(info, "map");
	}
}

void	map_setup(t_info *info, int max_y, int max_x, t_list *lst)
{
	t_list	*curr;
	int		i;

	curr = lst;
	info->ptype.check_exit = 2;
	if (!(info->map.data = malloc(sizeof(char *) * max_y)))
		exit_msg(info, "malloc");
	info->map.width = max_x;
	info->map.height = max_y;
	i = -1;
	while (++i < max_y)
	{
		if (!(info->map.data[i] = malloc(max_x + 1)))
			exit_msg(info, "malloc");
		ft_memset(info->map.data[i], ' ', max_x);
		ft_memmove(info->map.data[i], curr->content, ft_strlen(curr->content));
		info->map.data[i][max_x] = 0;
		curr = curr->next;
	}
	ft_lstclear(&lst, free);
}

void	map_parsing(t_info *info, int fd, char *line, int *gnl_check)
{
	int		max;
	t_list	*curr;
	t_list	*tmp;

	if (!(curr = ft_lstnew(line)))
		exit_msg(info, "malloc");
	max = ft_strlen(line);
	while ((*gnl_check = get_next_line(fd, &line) >= 0) && ft_strlen(line))
	{
		if (!(tmp = ft_lstnew(line)))
			exit_msg(info, "malloc");
		ft_lstadd_back(&curr, tmp);
		if (max < (int)ft_strlen(line))
			max = ft_strlen(line);
	}
	if (*gnl_check < 0)
		exit_msg(info, "map");
	free(line);
	map_setup(info, ft_lstsize(curr), max, curr);
}

int		init_player(t_info *info, t_floatxy pos)
{
	info->pos = pos;
	if (info->map.data[(int)pos.y][(int)pos.x] == 'N')
		info->dir = put_xy(0, -1);
	else if (info->map.data[(int)pos.y][(int)pos.x] == 'S')
		info->dir = put_xy(0, 1);
	else if (info->map.data[(int)pos.y][(int)pos.x] == 'W')
		info->dir = put_xy(-1, 0);
	else if (info->map.data[(int)pos.y][(int)pos.x] == 'E')
		info->dir = put_xy(1, 0);
	info->map.data[(int)pos.y][(int)pos.x] = '0';
	info->plane = put_xy(cos(1.57), sin(1.57));
	info->plane.x = info->dir.y * -FOV;
	info->plane.y = info->dir.x * FOV;
	return (1);
}

void	init_map(t_info *info, int fd, char *line, int *gnl_check)
{
	int	x;
	int	y;
	int	check;

	check = -1;
	y = -1;
	map_parsing(info, fd, line, gnl_check);
	while (++y < info->map.height)
	{
		x = -1;
		while (++x < info->map.width)
		{
			check_map(info, x, y);
			if (ft_strchr("NSWE", info->map.data[y][x]))
				check += init_player(info, put_xy(x + 0.5, y + 0.5));
			if (info->map.data[y][x] > 49)
				info->sprite.snum += 1;
		}
	}
	if (check)
		exit_msg(info, "map");
}
