/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:10:32 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/05 14:12:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_standart.h"

char		*ft_strcat(char *dest, const char *src)
{
	char	*iter;

	iter = dest + ft_strlen(dest);
	ft_strcpy(iter, src);
	return (dest);
}
