/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 20:10:47 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/05 20:22:46 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_dancing_link.h"

void						dancing_link_print
	(t_dancing_link *me, void (*f)(void *))
{
	t_dancing_link			**iter[2];

	if (!me)
		return ;
	iter[0] = &me;
	while (1)
	{
		iter[1] = iter[0];
		while (*iter[0])
		{
			f((*iter[0])->data);
			iter[0] = &(*iter[0])->right;
		}
		iter[0] = iter[1];
		iter[0] = &(*iter[0])->lower;
		ft_printf("\n");
		if (!*iter[0])
			return ;
	}
}
