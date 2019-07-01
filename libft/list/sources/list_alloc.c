/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 13:31:10 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/06 13:31:25 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

t_list			*list_alloc(void const *content, size_t content_size)
{
	t_list		*piece;

	if (!(piece = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
		piece->content = NULL;
	else
	{
		if (!(piece->content = malloc(content_size)))
		{
			free(piece);
			return (NULL);
		}
		ft_memcpy(piece->content, content, content_size);
	}
	piece->next = NULL;
	return (piece);
}
