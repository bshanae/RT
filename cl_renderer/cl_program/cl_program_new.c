/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_program_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:59:13 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl_program.h"

t_cl_program		*cl_program_new(CHAR_REF path)
{
	t_cl_program	*new;

	new = (t_cl_program *)rt_malloc(sizeof(t_cl_program));
	new->length = 0;
	new->capacity = RT_PROGRAM_INIT;
	new->buffer = rt_malloc(RT_PROGRAM_INIT);
	ft_strcpy(new->path, path);
	return (new);
}
