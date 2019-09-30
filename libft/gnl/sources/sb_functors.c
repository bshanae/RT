/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb_fd_cmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 21:21:34 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/07 18:25:33 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_gnl.h"

int					sb_fd_cmp(const void *value_ptr, const void *m)
{
	int				*value;
	t_sb			*sb;

	value = (int *)value_ptr;
	sb = *(t_sb **)m;
	return (*value - sb->fd);
}
