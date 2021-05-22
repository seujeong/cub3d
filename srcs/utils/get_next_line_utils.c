/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeong <seujeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 00:00:15 by hyeojang          #+#    #+#             */
/*   Updated: 2021/05/22 20:59:49 by seujeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	ft_strlen(const char *s)
{
	size_t len;

	if (!s)
		return (0);
	len = 0;
	while (*s++)
		len++;
	return (len);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*de;
	const unsigned char	*sr;

	if (!dest && !src)
		return (0);
	de = dest;
	sr = src;
	while (n-- > 0)
	{
		*de++ = *sr++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(result = (char *)malloc(sizeof(char) + (len1 + len2 + 1))))
		return (0);
	ft_memcpy(result, s1, len1);
	ft_memcpy(result + len1, s2, len2);
	result[len1 + len2] = '\0';
	return (result);
}

char	*ft_strndup(const char *s, size_t n)
{
	char	*result;

	if (!(result = (char *)malloc(sizeof(char) * (n + 1))))
		return (0);
	ft_memcpy(result, s, n);
	result[n] = '\0';
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != c)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return (char *)s;
}
