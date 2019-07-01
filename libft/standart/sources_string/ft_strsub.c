/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:28:10 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/07 21:29:31 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_standart.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res_str;
	size_t	res_i;

	if (!s)
		return (NULL);
	if (!(res_str = (char *)malloc(len + 1)))
		return (NULL);
	res_i = 0;
	while (res_i < len)
		res_str[res_i++] = s[start++];
	res_str[res_i] = '\0';
	return (res_str);
}
