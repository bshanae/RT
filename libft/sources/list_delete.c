/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 13:30:54 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/07 18:03:56 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

t_list				*list_delete
	(t_list **alst, const void *content,
	int (*cmp)(const void *, const void *), void (*del)(void *))
{
	t_list			*iter;
	t_list			*prev;

	if (!alst || !*alst)
		return (NULL);
	iter = *alst;
	prev = NULL;
	while (iter)
	{
		if (cmp && !cmp(content, iter->content))
			break ;
		else if (!cmp && iter->content == content)
			break ;
		prev = iter;
		iter = iter->next;
	}
	if (!iter)
		return (NULL);
	if (!prev)
		*alst = (*alst)->next;
	else
		prev->next = iter->next;
	list_free(&iter, del);
	return (prev ? prev->next : *alst);
}
