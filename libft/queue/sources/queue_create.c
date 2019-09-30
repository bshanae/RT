/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 20:21:37 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/05 20:22:46 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_queue.h"

t_queue						queue_create(long data_size)
{
	t_queue					new;

	new.begin = NULL;
	new.end = NULL;
	new.data_size = data_size;
	new.length = 0 - (data_size < 1);
	return (new);
}
