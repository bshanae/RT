/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:40:25 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/09 20:18:16 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_standart.h"

char		*ft_strrchr(const char *str, int value)
{
	const char	*tmp_res;
	char		value_chr;

	tmp_res = NULL;
	value_chr = (char)value;
	while (1)
	{
		if (*str == value_chr)
			tmp_res = str;
		if (!*str)
			break ;
		str++;
	}
	return ((char *)tmp_res);
}
