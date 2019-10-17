/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_raise_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:35:30 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_framework.h"

void				rt_raise_warning(CHAR_REF message, ...)
{
	va_list			args;

	va_start(args, message);
	rt_print_warning(message, args);
	va_end(args);
	if (RT_W_ERROR)
		exit(2);
}

void				rt_raise_error(CHAR_REF message, ...)
{
	va_list			args;

	va_start(args, message);
	rt_print_error(message, args);
	va_end(args);
	exit(1);
}
