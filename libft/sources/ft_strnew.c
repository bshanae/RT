/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:52:31 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/12 16:07:36 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_standart.h"

char	*ft_strnew(size_t size)
{
	char *str;

	if (size == ((size_t)-1))
		return (NULL);
	str = (char *)ft_memalloc(size + 1);
	return (str);
}
