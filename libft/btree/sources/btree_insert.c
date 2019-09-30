/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreeinsert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:22:04 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/11 12:52:51 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_btree.h"

t_btree		*btree_insert
	(t_btree **root, const void *content, size_t content_size,
	int (*cmpf)(const void *, const void *))
{
	if (!root || !cmpf)
		return (NULL);
	if (!*root)
		return (*root = btree_alloc(content, content_size));
	if (cmpf(content, (*root)->content) < 0)
		return (btree_insert(&((*root)->left), content, content_size, cmpf));
	else
		return (btree_insert(&((*root)->right), content, content_size, cmpf));
}
