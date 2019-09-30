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

void		btree_suffix(t_btree *root, void (*f)(void *))
{
	if (!root || !f)
		return ;
	btree_suffix(root->left, f);
	btree_suffix(root->right, f);
	f(root->content);
}
