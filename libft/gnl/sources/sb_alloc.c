/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 21:50:32 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/26 21:50:53 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_gnl.h"

t_sb			*sb_alloc(int fd, int size, char **target)
{
	t_sb		*new;

	if (!(new = (t_sb *)malloc(sizeof(t_sb))))
		return (NULL);
	new->fd = fd;
	new->size = size;
	if (!(new->begin = (char *)malloc(new->size)))
		return (NULL);
	new->end = new->begin + size;
	new->out_begin = new->begin;
	new->out_end = NULL;
	new->in = new->begin;
	new->target = target;
	return (new);
}
