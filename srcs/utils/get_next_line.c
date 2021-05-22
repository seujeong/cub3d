/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeong <seujeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 23:59:37 by hyeojang          #+#    #+#             */
/*   Updated: 2021/05/22 20:59:52 by seujeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		savejoin(char **save, char *buf, size_t read_size)
{
	char	*tmp;

	buf[read_size] = '\0';
	if (0 != *save)
	{
		tmp = ft_strjoin(*save, buf);
		free(*save);
	}
	else
		tmp = ft_strndup(buf, read_size);
	*save = tmp;
	if (ft_strchr(*save, '\n'))
		return (1);
	return (0);
}

int		ft_check_line(char **save, char **line)
{
	char *ptr;
	char *tmp;

	if ((ptr = ft_strchr(*save, '\n')))
	{
		*line = ft_strndup(*save, ptr - *save);
		tmp = ft_strndup(ptr + 1, ft_strlen(ptr + 1));
		free(*save);
		*save = tmp;
		return (1);
	}
	else
	{
		*line = *save;
		*save = 0;
		return (0);
	}
}

int		get_next_line(int fd, char **line)
{
	static char	*save[OPEN_MAX];
	ssize_t		read_size;
	char		buf[BUFFER_SIZE + 1];

	if (fd < 0 || fd >= OPEN_MAX || !line || BUFFER_SIZE <= 0)
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) >= 0)
	{
		if (savejoin(&save[fd], buf, read_size) || read_size == 0)
			break ;
	}
	if (read_size < 0)
		return (-1);
	return (ft_check_line(&save[fd], line));
}
