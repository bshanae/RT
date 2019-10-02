/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 10:09:51 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/05 20:22:46 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_standart.h"

void		*ft_memset(void *str, int c, size_t n)
{
	u_char	*uc_str;
	u_long	*ul_str;
	u_long	ul_c;

	uc_str = (u_char *)str;
	while (n % 8)
	{
		*(uc_str++) = (u_char)c;
		n--;
	}
	ul_c = 0x0101010101010101 * (u_char)c;
	ul_str = (u_long *)uc_str;
	while (n > 0)
	{
		*(ul_str++) = ul_c;
		n -= 8;
	}
	return (str);
}
