/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:35:18 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/14 13:35:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_framework.h"

void				rt_print_warning(CHAR_REF message, va_list args)
{
	printf("\033[0;31m");
	printf("RT_WARNING : ");
	vprintf(message, args);
	printf("\n");
	printf("\033[0m");
}

void				rt_print_error(CHAR_REF message, va_list args)
{
	printf("\033[0;31m");
	printf("RT_ERROR : ");
	vprintf(message, args);
	printf("\n");
	printf("\033[0m");
}
