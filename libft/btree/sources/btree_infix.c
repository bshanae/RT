/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreeinfix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:20:59 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/11 12:47:45 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_btree.h"

void	btree_infix(t_btree *root, void (*f)(void *))
{
	if (!root || !f)
		return ;
	btree_infix(root->left, f);
	f(root->content);
	btree_infix(root->right, f);
}
