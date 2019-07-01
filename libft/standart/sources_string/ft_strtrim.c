/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:36:57 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/12 14:14:21 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_standart.h"

char		*ft_strtrim(char const *s)
{
	char		*res_str;
	int			res_i;
	const char	*s_begin;
	const char	*s_end;

	if (!s)
		return (NULL);
	s_begin = s;
	while (*s_begin && is_space(s_begin))
		s_begin++;
	s_end = s_begin;
	while (*s_end)
		s_end++;
	while ((s_end - 1) != s && is_space(s_end - 1))
		s_end--;
	if (s_end <= s_begin)
		return (ft_strnew(1));
	if (!(res_str = (char *)malloc(s_end - s_begin + 1)))
		return (NULL);
	res_i = 0;
	while (s_begin < s_end)
		res_str[res_i++] = *(s_begin++);
	res_str[res_i] = '\0';
	return (res_str);
}
