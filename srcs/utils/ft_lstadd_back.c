/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seujeong <seujeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 20:46:47 by sanoh             #+#    #+#             */
/*   Updated: 2021/05/22 20:59:14 by seujeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_lstadd_back(t_list **lst, t_list *new_list)
{
	if (*lst == 0)
		*lst = new_list;
	else
		(ft_lstlast(*lst))->next = new_list;
}
