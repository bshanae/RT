/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:48:53 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/12 14:11:08 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_standart.h"

static int	unit_count(int n)
{
	int		count;

	count = 0;
	if (n > 0)
		n *= -1;
	if (!n)
		return (1);
	while (n <= -1)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	char	*res_str;
	int		res_i;
	int		div;

	if (!(res_str = ft_strnew(unit_count(n) + (n < 0))))
		return (NULL);
	res_i = 0;
	if (n < 0)
		res_str[res_i++] = '-';
	div = 1000000000;
	while (ft_abs(n / div) < 1 && div > 1)
		div /= 10;
	while (div >= 1 || (!n && div))
	{
		res_str[res_i++] = '0' + ft_abs(n / div);
		n = n % div;
		div = div / 10;
	}
	return (res_str);
}
