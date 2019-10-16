/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreeclean.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:19:56 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/04 16:46:17 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_btree.h"

static void	clean_one(t_btree *node, void (*del)(void *))
{
	if (node->left)
		clean_one(node->left, del);
	if (node->right)
		clean_one(node->right, del);
	if (del)
		del(node->content);
	free(node->content);
	free(node);
}

void		btree_clean(t_btree **root, void (*del)(void *))
{
	if (!root || !*root)
		return ;
	clean_one(*root, del);
	*root = NULL;
}
