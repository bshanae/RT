/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:59:11 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/05 16:05:21 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_standart.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (i < n && str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			while (i + j < n &&
					str[i + j] != '\0' &&
					str[i + j] == to_find[j])
				j++;
			if (to_find[j] == '\0')
				return ((char *)(str + i));
		}
		i++;
	}
	return (NULL);
}
