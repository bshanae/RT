/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreedepth.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:21:12 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/12 14:12:25 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_btree.h"

int			btree_depth(t_btree **root)
{
	int		left_depth;
	int		right_depth;

	if (!root)
		return (0);
	if (!*root)
		return (1);
	left_depth = btree_depth(&((*root)->left));
	right_depth = btree_depth(&((*root)->right));
	return (1 + ft_max(left_depth, right_depth));
}
