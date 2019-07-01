/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreesuffix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:24:17 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/11 12:49:33 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_btree.h"

int			btree_verify
	(t_btree **root, int (*cmpf)(const void *, const void *))
{
	if (!root || !cmpf)
		return (0);
	if ((*root)->left)
	{
		if (cmpf((*root)->content, (*root)->left->content) < 0)
			return (0);
		if (!btree_verify(&((*root)->left), cmpf))
			return (0);
	}
	if ((*root)->right)
	{
		if (cmpf((*root)->content, (*root)->right->content) >= 0)
			return (0);
		if (!btree_verify(&((*root)->right), cmpf))
			return (0);
	}
	return (1);
}
