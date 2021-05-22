/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_resolution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeong <seujeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 19:22:55 by sanoh             #+#    #+#             */
/*   Updated: 2021/05/22 20:58:15 by seujeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

int		itoa(t_info *info, char *word)
{
	int		len;
	int		n;

	n = 0;
	len = ft_strlen(word);
	while (len > 0 && ft_strchr("0123456789", *word))
	{
		n *= 10;
		n += *word++ - '0';
		--len;
	}
	if (len != 0)
		exit_msg(info, "resolution");
	return (n);
}

void	parse_resolution(t_info *info, char **split)
{
	info->ptype.resolution_x = itoa(info, split[0]);
	info->ptype.resolution_y = itoa(info, split[1]);
	if (info->ptype.resolution_x < info->img.width)
		info->img.width = info->ptype.resolution_x;
	if (info->ptype.resolution_y < info->img.height)
		info->img.height = info->ptype.resolution_y;
	check_parse(info, R);
}
