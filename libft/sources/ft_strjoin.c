/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:32:16 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/07 21:19:06 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_standart.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res_str;
	int		res_i;

	if (!s1 || !s2)
		return (NULL);
	if (!(res_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	res_i = 0;
	while (*s1)
		res_str[res_i++] = *(s1++);
	while (*s2)
		res_str[res_i++] = *(s2++);
	res_str[res_i] = '\0';
	return (res_str);
}
