/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 10:09:37 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/05 20:22:46 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_standart.h"

void		*ft_memccpy(void *dest, const void *src, int value, size_t n)
{
	void	*limit;

	limit = ft_memchr(src, value, n);
	if (!limit)
	{
		ft_memcpy(dest, src, n);
		return (NULL);
	}
	else
		return (ft_memcpy(dest, src, limit - src + 1) + (limit - src + 1));
}
