/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:10:42 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/05 15:14:40 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_standart.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	unsigned char *p1;
	unsigned char *p2;

	p1 = (unsigned char*)str1;
	p2 = (unsigned char*)str2;
	while (*p1 || *p2)
		if (*(p1++) != *(p2++))
			return (*(p1 - 1) - *(p2 - 1));
	return (0);
}
