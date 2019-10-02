/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:16:27 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/17 15:41:39 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_standart.h"

int			ft_memcmp(const void *str1, const void *str2, size_t n)
{
	u_long	*ul_str1;
	u_long	*ul_str2;
	u_char	*uc_str1;
	u_char	*uc_str2;

	ul_str1 = (u_long *)str1;
	ul_str2 = (u_long *)str2;
	while (n >= 8 && *ul_str1 == *ul_str2)
	{
		ul_str1++;
		ul_str2++;
		n -= 8;
	}
	uc_str1 = (u_char *)ul_str1;
	uc_str2 = (u_char *)ul_str2;
	while (n > 0)
	{
		if (*(uc_str1++) != *(uc_str2++))
			return (*(uc_str1 - 1) - *(uc_str2 - 1));
		n--;
	}
	return (0);
}
