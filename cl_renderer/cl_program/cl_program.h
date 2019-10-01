/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_program.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:58:52 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CL_PROGRAM_H
# define CL_PROGRAM_H

# include "rt_parameters.h"
# include "rt_cl_include.h"

# include "error_framework.h"
# include "libft_standart.h"

# include <stdlib.h>

typedef struct		s_cl_program
{
	cl_program		program;
	char			*buffer;
	u_long			capacity;
	u_long			length;
	int				error;
	char			path[64];
}					t_cl_program;

t_cl_program		*cl_program_new(CHAR_REF path);
void				cl_program_delete(t_cl_program **program);

void				cl_program_concat(t_cl_program *program, CHAR_REF file);
int					cl_program_build
					(t_cl_program *program, cl_context context, CHAR_REF flags);

#endif
