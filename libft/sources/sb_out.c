/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 20:45:28 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/07 18:26:38 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_gnl.h"

int				sb_out(t_sb *sb)
{
	*(sb->target) = NULL;
	if (!sb->out_end)
	{
		if (sb->out_begin >= sb->in || sb->in == sb->out_begin)
			return (SB_OUT_EOF);
		else
			sb->out_end = sb->in;
	}
	if (!(*(sb->target) = (char *)malloc(sb->out_end - sb->out_begin + 1)))
		return (SB_ERR_ALLOC);
	ft_memcpy(*(sb->target), sb->out_begin, sb->out_end - sb->out_begin);
	(*(sb->target))[sb->out_end - sb->out_begin] = '\0';
	sb->out_begin = sb->out_end + 1;
	sb->out_end = NULL;
	return (SB_OUT_MID);
}
