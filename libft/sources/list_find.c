/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 13:30:54 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/07 18:04:17 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

t_list				*list_find
	(t_list **alst, const void *content, int (*cmp)(const void *, const void *))
{
	t_list			*iter;

	if (!alst || !*alst)
		return (NULL);
	iter = *alst;
	while (iter)
	{
		if (cmp && !cmp(content, iter->content))
			break ;
		else if (!cmp && iter->content == content)
			break ;
		iter = iter->next;
	}
	return (iter);
}
