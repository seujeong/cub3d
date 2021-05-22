/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeong <seujeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 19:22:28 by sanoh             #+#    #+#             */
/*   Updated: 2021/05/22 20:58:40 by seujeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

int		itoa_c(t_info *info, char *word)
{
	int		len;
	int		n;

	n = 0;
	if (!(len = ft_strlen(word)))
		exit_msg(info, "background color");
	while (len > 0 && ft_strchr("0123456789", *word))
	{
		n *= 10;
		n += *word++ - '0';
		--len;
	}
	if (len != 0 || n > 256)
		exit_msg(info, "background color");
	return (n);
}

void	parse_color(t_info *info, int typefc, char *word)
{
	char	**split;
	int		count;
	int		type;
	int		color;
	int		i;

	i = 0;
	color = 0;
	split = ft_split(word, ',', &count);
	if (count != 3)
		exit_msg(info, "background color");
	type = 0;
	if (typefc == C)
		type = 1;
	while (split[i])
	{
		color = color | itoa_c(info, split[i]) << (16 - (i * 8));
		i++;
	}
	info->color[type].c = color;
	free_word(split, count);
	check_parse(info, typefc);
}
