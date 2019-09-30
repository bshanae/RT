/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 20:11:15 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/05 20:34:59 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_dancing_link.h"

static void					kostyl(t_dancing_link ***iter, t_dancing_link **res)
{
	iter[0] = res;
	iter[1] = NULL;
	iter[3] = res;
}

t_dancing_link				*dancing_link_create(int i, int j, long size)
{
	t_dancing_link			*res;
	t_dancing_link			**iter[4];
	int						count[2];

	res = NULL;
	kostyl(iter, &res);
	count[0] = 0;
	while (count[0]++ < i)
	{
		iter[2] = NULL;
		count[1] = 0;
		while (count[1]++ < j)
		{
			*iter[0] = dancing_link_allocate(NULL, size);
			dancing_link_connect_hor(iter[2], iter[0]);
			dancing_link_connect_ver(iter[1], iter[0]);
			iter[2] = iter[0];
			iter[1] = iter[1] ? &(*iter[1])->right : NULL;
			iter[0] = &(*iter[0])->right;
		}
		iter[1] = iter[3];
		iter[0] = &(*iter[1])->lower;
		iter[3] = iter[0];
	}
	return (res);
}
