/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:36:08 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/15 14:41:47 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_standart.h"

void		*ft_realloc(void **m, size_t old_size, size_t new_size)
{
	void		*tmp_m;

	if (!m)
		return (NULL);
	if (old_size == new_size)
		return (*m);
	if (!(tmp_m = malloc(new_size)))
		return (NULL);
	if (old_size)
	{
		ft_memcpy(tmp_m, *m, old_size);
		free(*m);
	}
	*m = tmp_m;
	return (*m);
}
