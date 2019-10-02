/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:20:15 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/05 20:22:46 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_standart.h"

static void		reverse_memcpy(void *dest, const void *src, size_t n)
{
	u_char		*uc_dest;
	u_char		*uc_src;
	u_long		*ul_dest;
	u_long		*ul_src;

	uc_dest = (u_char *)dest + n - 1;
	uc_src = (u_char *)src + n - 1;
	while (n % 8)
	{
		*(uc_dest--) = *(uc_src--);
		n--;
	}
	ul_dest = (u_long *)dest;
	ul_src = (u_long *)src;
	while (n >= 8)
	{
		*(ul_dest--) = *(ul_src--);
		n -= 8;
	}
}

void			*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest == src)
		return (dest);
	if (src < dest && src + n > dest)
		reverse_memcpy(dest, src, n);
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
