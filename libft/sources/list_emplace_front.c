/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 13:30:30 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/07 21:30:48 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

t_list				*list_emplace_front
	(t_list **alst, const void *content, size_t content_size)
{
	t_list			*new;

	new = list_alloc(content, content_size);
	if (!alst || !new)
		return (NULL);
	else if (!*alst)
		*alst = new;
	else
	{
		new->next = *alst;
		*alst = new;
	}
	return (*alst);
}
