/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_framework.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:33:41 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_ERROR_FRAMEWORK_H
# define RT_ERROR_FRAMEWORK_H

# include "libft_standart.h"

# include <stdio.h>
# include <stdarg.h>

# define RT_W_ERROR	0

void				rt_print_warning(CHAR_REF message, va_list args);
void				rt_print_error(CHAR_REF message, va_list args);

void				rt_raise_warning(CHAR_REF message, ...);
void				rt_raise_error(CHAR_REF message, ...);

void				rt_assert(int statement, CHAR_REF message, ...);
void				rt_assert_critical(int statement, CHAR_REF message, ...);

void				*rt_malloc(u_long size);

#endif
