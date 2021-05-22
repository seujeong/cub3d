/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeong <seujeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 19:22:48 by sanoh             #+#    #+#             */
/*   Updated: 2021/05/22 21:49:12 by seujeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	check_parse(t_info *info, int type)
{
	if (type == R)
		info->ptype.check *= 2;
	if (type == NO)
		info->ptype.check *= 3;
	if (type == SO)
		info->ptype.check *= 5;
	if (type == WE)
		info->ptype.check *= 7;
	if (type == EA)
		info->ptype.check *= 11;
	if (type == S)
		info->ptype.check *= 13;
	if (type == F)
		info->ptype.check *= 17;
	if (type == C)
		info->ptype.check *= 19;
}

int		check_type(char *line, t_info *info)
{
	if (line[0] == 'R' && line[1] == ' ')
		return (R);
	else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		return (NO);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		return (SO);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		return (WE);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		return (EA);
	else if (line[0] == 'S' && line[1] == ' ')
		return (S);
	else if (line[0] == 'F' && line[1] == ' ')
		return (F);
	else if (line[0] == 'C' && line[1] == ' ')
		return (C);
	else
		exit_msg(info, "map file");
	return (MAP);
}

void	check_information(t_info *info, char *line)
{
	int		type;
	char	**split;
	int		count;

	if (ft_strlen(line))
	{
		split = ft_split(line, ' ', &count);
		type = check_type(line, info);
		if (type == R && count == 3)
			parse_resolution(info, &split[1]);
		else if (type >= NO && type <= S && count == 2)
			parse_texture(info, type, split[1]);
		else if ((type == F || type == C) && count == 2)
			parse_color(info, type, split[1]);
		free_word(split, count);
	}
	if (info->ptype.check == 9699690)
		info->ptype.map = 1;
	free(line);
}

int		check_cub(char *av)
{
	int	len;

	if ((len = ft_strlen(av)) < 4)
		return (0);
	if (av[len - 1] == 'b' && av[len - 2] == 'u'
		&& av[len - 3] == 'c' && av[len - 4] == '.')
		return (1);
	return (0);
}

void	init_parse(t_info *info, char *av)
{
	int		fd;
	int		gnl_check;
	char	*line;

	if (check_cub(av) == 0)
		exit_msg(info, "file name error");
	if (!(fd = open(av, O_RDONLY)))
		exit_msg(info, "map file error");
	while (info->ptype.map == 0 &&
	((gnl_check = get_next_line(fd, &line)) >= 0))
		check_information(info, line);
	if (info->ptype.map == 0)
		exit_msg(info, "map file error");
	if (gnl_check < 0)
		exit_msg(info, "read error");
	while ((gnl_check = get_next_line(fd, &line)) > 0 && !ft_strlen(line))
		free(line);
	init_map(info, fd, line, &gnl_check);
	close(fd);
}
