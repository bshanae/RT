/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 18:02:59 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/21 18:12:23 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ft_printf.h"

int						is_digit(const char *c)
{
	return (*c >= '0' && *c <= '9');
}

void					print_bits
	(unsigned long long value, u_int len, int endl)
{
	unsigned long long	marker;
	u_int				i;
	char				temp;

	marker = 1lu << (len - 1);
	i = 0;
	while (i < len)
	{
		temp = '0' + ((value & marker) >> ((len - 1u) - i));
		write(1, &temp, 1);
		marker >>= 1u;
		i++;
	}
	if (endl)
		write(1, "\n", 1);
}

double					safe_atof(const char *str)
{
	double				res;

	res = 0;
	while (is_digit(str))
		res = res * 10 + *(str++) - '0';
	return (res);
}

char					get_digit(int i, int is_upper)
{
	static char			field[16];

	if (i > 15)
		return ('\0');
	if (!field[0])
		ft_memcpy(field, "0123456789abcdef", 16);
	if (i > 9 && is_upper)
		return (field[i] - 32);
	else
		return (field[i]);
}

void					fast_char_out(int fd, char c, int len)
{
	char				small_buff[128];

	ft_memset(small_buff, c, 128);
	while (len > 128)
	{
		write(fd, small_buff, 128);
		len -= 128;
	}
	while (len > 0)
	{
		write(fd, &c, 1);
		len--;
	}
}
