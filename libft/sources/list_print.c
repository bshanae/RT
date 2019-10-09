/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 13:31:31 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/07 21:31:53 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

void				list_print
	(t_list **alst, void (*print)(const void *content))
{
	const t_list	*iter;

	if (!alst || !print)
		return ;
	if (!*alst)
	{
		write(1, "List is empty\n", 15);
		return ;
	}
	iter = *alst;
	while (iter)
	{
		print(iter->content);
		if (iter->next)
			write(1, " -> ", 4);
		iter = iter->next;
	}
	write(1, "\n", 1);
}
