/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 10:09:45 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/05 20:23:33 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_standart.h"

void			*ft_memcpy(void *dest, const void *src, size_t n)
{
	u_char		*uc_dest;
	u_char		*uc_src;
	u_long		*ul_dest;
	u_long		*ul_src;

	if (dest == src)
		return (dest);
	uc_dest = (u_char *)dest;
	uc_src = (u_char *)src;
	while (n % 8)
	{
		*(uc_dest++) = *(uc_src++);
		n--;
	}
	ul_dest = (u_long *)uc_dest;
	ul_src = (u_long *)uc_src;
	while (n >= 8)
	{
		*(ul_dest++) = *(ul_src++);
		n -= 8;
	}
	return (dest);
}
