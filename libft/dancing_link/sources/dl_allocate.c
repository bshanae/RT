/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_allocate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 20:10:35 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/05 20:22:46 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_dancing_link.h"

t_dancing_link				*dancing_link_allocate(const void *data, long size)
{
	t_dancing_link			*new;

	if (size < 0)
		return (NULL);
	if (!(new = (t_dancing_link *)malloc(sizeof(t_dancing_link))))
		exit(1);
	new->right = NULL;
	new->upper = NULL;
	new->left = NULL;
	new->lower = NULL;
	if (size > 0 && !(new->data = malloc(size)))
		exit(1);
	if (data)
		ft_memcpy(new->data, data, size);
	return (new);
}
