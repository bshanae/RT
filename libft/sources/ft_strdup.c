/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:18:28 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/05 16:59:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_standart.h"

char	*ft_strdup(const char *src)
{
	char	*res_str;
	int		res_len;

	res_len = ft_strlen(src);
	if (!(res_str = (char *)malloc(res_len + 1)))
		return (NULL);
	return (ft_strcpy(res_str, src));
}
