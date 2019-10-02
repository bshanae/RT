/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_arg.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:41:35 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CL_ARG_H
# define CL_ARG_H

# include "rt_cl_include.h"

typedef struct		s_cl_arg
{
	void			*host;
	cl_mem			device;
	u_long			size;
	int				update_need;
}					t_cl_arg;

#endif
