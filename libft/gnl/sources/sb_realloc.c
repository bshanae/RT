/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 21:55:35 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/26 22:11:03 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_gnl.h"

int				sb_realloc(t_sb *sb, int new_size)
{
	char		*temp_str;
	int			i_out;
	int			i_in;

	i_out = sb->out_begin - sb->begin;
	i_in = sb->in - sb->begin;
	if (new_size <= sb->size)
		return (SB_UNEXPECTED);
	if (!(temp_str = (char *)malloc(new_size)))
		return (SB_ERR_ALLOC);
	ft_memcpy(temp_str, sb->out_begin, sb->in - sb->out_begin);
	free(sb->begin);
	sb->begin = temp_str;
	sb->size = new_size;
	sb->end = sb->begin + new_size;
	sb->out_begin = sb->begin + i_out;
	sb->out_end = NULL;
	sb->in = sb->begin + i_in;
	return (SB_DEFAULT);
}
