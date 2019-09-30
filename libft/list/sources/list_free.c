/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 13:30:54 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/07 21:32:12 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

void				list_free(t_list **alst, void (*del)(void *))
{
	if (!alst || !*alst)
		return ;
	if (del)
		del((*alst)->content);
	free(*alst);
	*alst = NULL;
}
