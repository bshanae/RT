/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreeprefix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:24:42 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/04 16:39:00 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_btree.h"

void	btree_prefix(t_btree *root, void (*f)(void *))
{
	if (!root || !f)
		return ;
	f(root->content);
	btree_prefix(root->left, f);
	btree_prefix(root->right, f);
}
