/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 13:30:37 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/07 21:31:09 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

t_list				*list_push_back(t_list **alst, t_list *new)
{
	t_list *iter;

	if (!alst || !new)
		return (NULL);
	else if (!*alst)
		*alst = new;
	else
	{
		iter = *alst;
		while (iter->next)
			iter = iter->next;
		iter->next = new;
	}
	return (new);
}
