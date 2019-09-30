/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 17:28:41 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/06 17:30:41 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

t_list					*list_last(t_list **lst)
{
	int				i;
	t_list			*iter;

	i = 0;
	if (!lst)
		return (0);
	iter = *lst;
	while (iter->next)
		iter = iter->next;
	return ((t_list *)iter);
}
