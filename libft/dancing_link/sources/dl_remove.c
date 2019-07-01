/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_remove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 20:10:41 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/05 20:23:33 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_dancing_link.h"

void						dancing_link_remove(t_dancing_link **me)
{
	t_dancing_link			*temp;

	if (!me || !*me)
		return ;
	temp = *me;
	if (temp->right)
		temp->right->left = NULL;
	if (temp->upper)
		temp->upper->lower = NULL;
	if (temp->left)
		temp->left->right = NULL;
	if (temp->lower)
		temp->lower->upper = NULL;
	free(temp->data);
	free(temp);
	*me = NULL;
}
