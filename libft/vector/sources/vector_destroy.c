/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:07:44 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/14 16:07:46 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_vector.h"

void						vector_destroy(t_vector *me)
{
	free(me->storage);
	me->storage = NULL;
	me->element_size = 0;
	me->capacity = 0;
	me->length = 0;
}
