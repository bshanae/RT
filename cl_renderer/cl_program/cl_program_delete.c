/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_program_delete.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:59:07 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl_program.h"

void				cl_program_delete(t_cl_program **program)
{
	free((*program)->buffer);
	(*program)->buffer = NULL;
	(*program)->capacity = 0;
	(*program)->length = -1;
	clReleaseProgram((*program)->program);
	free(*program);
}
