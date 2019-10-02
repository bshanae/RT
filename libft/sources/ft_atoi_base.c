/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:55:25 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/07 18:02:12 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_standart.h"

static int			is_delim(char c)
{
	return (c == '\t' || c == '\r' ||
			c == '\n' || c == '\v' ||
			c == ' ');
}

static int			is_num(char c)
{
	return (c >= '0' && c <= '9');
}

static int			get_digit(char c)
{
	int				i;
	char			temp;

	i = 0;
	temp = '0';
	while (temp <= '9')
		if (c == temp++)
			return (temp - '0' - 1);
	temp = 'A' - 1;
	while (temp++ <= 'F')
		if (c == temp)
			return (temp - 'A' + 10);
		else if (c == temp + 32)
			return (temp - 'a' + 10);
	return (-1);
}

int					ft_atoi_base(const char *str, int base)
{
	long			num;
	int				sign;
	int				next;

	if (!str || base < 2 || base > 16)
		return (0);
	num = 0;
	sign = 1;
	while (is_delim(*str))
		str++;
	if ((*str == '-' || *str == '+') && is_num(*(str + 1)))
		sign = *(str++) == '-' ? -1 : 1;
	while (*str && (next = get_digit(*(str++))) != -1)
		num = num * base + next;
	return ((int)(num * sign));
}
