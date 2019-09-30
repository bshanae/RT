/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_at.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 20:09:45 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/05 20:22:46 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_dancing_link.h"

t_dancing_link				**dancing_link_at
	(t_dancing_link **me, int i, int j)
{
	if (!i && !j)
		return (me);
	if (!me || !*me)
		return (NULL);
	if (j > 0)
		return (dancing_link_at(&(*me)->right, i, j - 1));
	if (j < 0)
		return (dancing_link_at(&(*me)->left, i, j + 1));
	if (i > 0)
		return (dancing_link_at(&(*me)->lower, i - 1, j));
	if (i < 0)
		return (dancing_link_at(&(*me)->upper, i + 1, j));
	return (NULL);
}
