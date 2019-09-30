/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_connect_hor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 20:09:56 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/05 20:22:46 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_dancing_link.h"

void						dancing_link_connect_hor
	(t_dancing_link **left, t_dancing_link **right)
{
	if (!left || !right)
		return ;
	if (*right)
		(*right)->left = *left;
	if (*left)
		(*left)->right = *right;
}
