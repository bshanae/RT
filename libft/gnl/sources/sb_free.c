/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 21:15:31 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/26 21:51:03 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_gnl.h"

void			sb_free(void *m)
{
	t_sb		*sb;

	sb = (t_sb *)m;
	sb->fd = -1;
	sb->size = -1;
	free(sb->begin);
	sb->begin = NULL;
	sb->out_begin = NULL;
	sb->out_end = NULL;
	sb->in = NULL;
	sb->target = NULL;
}
