/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_xy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeong <seujeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 18:03:00 by hyeojang          #+#    #+#             */
/*   Updated: 2021/05/22 20:59:56 by seujeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_floatxy		put_xy(float x, float y)
{
	t_floatxy	result;

	result.x = x;
	result.y = y;
	return (result);
}
