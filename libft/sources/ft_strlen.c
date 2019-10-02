/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:11:23 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/05 14:17:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_standart.h"

size_t		ft_strlen(const char *str)
{
	int count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}
