/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeong <seujeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 20:40:42 by hyeojang          #+#    #+#             */
/*   Updated: 2021/05/22 20:59:34 by seujeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dp;
	const unsigned char	*sp;

	if (!dest && !src)
		return (0);
	if (dest > src)
	{
		dp = dest + n;
		sp = src + n;
		while (n-- > 0)
		{
			*--dp = *--sp;
		}
	}
	else
	{
		dp = dest;
		sp = src;
		while (n-- > 0)
		{
			*dp++ = *sp++;
		}
	}
	return (dest);
}
