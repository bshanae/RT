/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 20:10:25 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/05 20:22:46 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_dancing_link.h"

void						dancing_link_destroy
	(t_dancing_link **me)
{
	if (!me || !*me)
		return ;
	if ((*me)->right)
		dancing_link_destroy(&(*me)->right);
	if ((*me)->upper)
		dancing_link_destroy(&(*me)->upper);
	if ((*me)->left)
		dancing_link_destroy(&(*me)->left);
	if ((*me)->lower)
		dancing_link_destroy(&(*me)->lower);
	free((*me)->data);
	free(*me);
	*me = NULL;
}
