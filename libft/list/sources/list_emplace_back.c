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

t_list				*list_emplace_back
	(t_list **alst, const void *content, size_t content_size)
{
	t_list			*iter;
	t_list			*new;

	new = list_alloc(content, content_size);
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
