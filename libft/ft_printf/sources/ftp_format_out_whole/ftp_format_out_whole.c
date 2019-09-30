/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_format_out_whole.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:58:47 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/23 13:58:47 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ft_printf.h"

void					ftp_format_out_whole(t_ftp_control *ctrl)
{
	t_ftp_whole_params	w_params;

	if (ctrl->format.precision != -1)
		ctrl->format.flags.zero = 0;
	ftp_format_out_whole_init(&w_params, ctrl);
	ftp_format_out_whole_process(ctrl, &w_params);
	ftp_format_out_whole_out(&w_params, ctrl);
}
