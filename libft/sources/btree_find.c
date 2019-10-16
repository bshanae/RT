/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreefind.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:23:08 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/11 12:52:39 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_btree.h"

t_btree		*btree_find
	(t_btree **root, const void *content,
	int (*cmpf)(const void *, const void *))
{
	int cmp_res;

	if (!root || !*root | !root || !cmpf)
		return (NULL);
	cmp_res = cmpf(content, (*root)->content);
	if (!cmp_res)
		return ((t_btree *)*root);
	else
		return (btree_find(((cmp_res < 0) ?
				&((*root)->left) :
				&((*root)->right)),
				content, cmpf));
}
