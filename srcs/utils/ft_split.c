/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeong <seujeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:00:53 by hyeojang          #+#    #+#             */
/*   Updated: 2021/05/22 20:59:41 by seujeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static size_t	ft_wordlen(char const *s, char c)
{
	size_t len;

	len = 0;
	while (*s && *s++ != c)
		len++;
	return (len);
}

static size_t	ft_count_word(char const *s, char c)
{
	size_t count;

	count = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		count++;
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	return (count);
}

void			ft_free_split(char **s, int cnt)
{
	while (cnt--)
		free(s[cnt]);
	free(s);
}

char			**ft_split(char const *s, char c, int *cnt)
{
	char	**result;
	size_t	count;
	size_t	wordlen;
	size_t	i;

	count = ft_count_word(s, c);
	if (!(result = (char **)malloc(sizeof(char *) * (count + 1))))
		return (0);
	i = 0;
	while (i < count)
	{
		while (*s && *s == c)
			s++;
		wordlen = ft_wordlen(s, c);
		if (!(result[i] = ft_strndup(s, wordlen)))
		{
			ft_free_split(result, i - 1);
			return (0);
		}
		s += wordlen;
		i++;
	}
	result[count] = 0;
	(*cnt) = count;
	return (result);
}
