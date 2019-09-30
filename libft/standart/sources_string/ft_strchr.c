/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:31:13 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/05 15:39:15 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_standart.h"

char		*ft_strchr(const char *str, int value)
{
	size_t len;

	len = ft_strlen(str);
	return (ft_memchr(str, value, len));
}
