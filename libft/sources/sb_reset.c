/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 21:55:54 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/26 22:11:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_gnl.h"

void			sb_reset(t_sb *sb)
{
	int			remain_len;

	remain_len = sb->in - sb->out_begin;
	ft_memmove(sb->begin, sb->out_begin, remain_len);
	sb->out_begin = sb->begin;
	sb->in = sb->begin + remain_len;
}
