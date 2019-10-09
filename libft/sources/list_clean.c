/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 13:30:47 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/07 21:31:33 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

void				list_clean(t_list **alst, void (*del)(void *))
{
	t_list			*iter;
	t_list			*next;

	if (!alst)
		return ;
	iter = (alst) ? (*alst) : (NULL);
	while (iter)
	{
		next = iter->next;
		list_free(&iter, del);
		iter = next;
	}
	if (alst)
		*alst = NULL;
}
