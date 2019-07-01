/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:10:54 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/05 14:30:45 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_standart.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (1)
	{
		dest[i] = src[i];
		if (!src[i])
			break ;
		i++;
	}
	return (dest);
}
