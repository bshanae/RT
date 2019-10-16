/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreenew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:24:50 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/08 17:01:07 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_btree.h"

t_btree		*btree_alloc(const void *content, size_t content_size)
{
	t_btree	*new;

	if (!(new = (t_btree *)malloc(sizeof(t_btree))))
		return (NULL);
	if (!(new->content = malloc(content_size)))
	{
		free(new);
		return (NULL);
	}
	ft_memcpy(new->content, content, content_size);
	new->left = NULL;
	new->right = NULL;
	return (new);
}
