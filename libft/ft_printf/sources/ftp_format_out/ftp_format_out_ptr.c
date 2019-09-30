/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_format_out_ptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:54:17 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/23 13:54:17 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ft_printf.h"

void					ftp_format_out_ptr(t_ftp_control *ctrl)
{
	ctrl->format.flags.hash = 1;
	ftp_format_out_whole(ctrl);
}
