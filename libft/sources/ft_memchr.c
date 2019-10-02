/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:13:46 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/05 13:22:53 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_standart.h"

#define V1	0x0101010101010101u
#define V2	0x0808080808080808u

void		*ft_memchr(const void *str, int value, size_t n)
{
	u_char	*uc_str;
	u_long	*ul_str;
	u_long	marker[2];

	ul_str = (u_long *)str;
	marker[0] = V1 * (u_char)value;
	while (n >= 8)
	{
		marker[1] = marker[0] ^ *ul_str;
		if ((marker[1] - V1) & (~marker[1] & V2))
			break ;
		n -= 8;
		ul_str++;
	}
	uc_str = (u_char *)ul_str;
	while (n > 0)
	{
		if (*(uc_str++) == (u_char)value)
			return ((void *)(u_long *)(uc_str - 1));
		n--;
	}
	return (NULL);
}
