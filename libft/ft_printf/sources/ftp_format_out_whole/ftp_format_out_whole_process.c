/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_format_out_whole_process.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:57:50 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/23 13:57:53 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ft_printf.h"

void			ftp_format_out_whole_process
	(t_ftp_control *ctrl, t_ftp_whole_params *whole)
{
	int			i;

	if (!ctrl->format.precision && !whole->copy &&
		!(ctrl->format.flags.hash && whole->base == 8))
	{
		whole->num_len = 0;
		return ;
	}
	i = FTP_STR_NUM_SIZE - 1;
	while (whole->copy > 0 || i == FTP_STR_NUM_SIZE - 1)
	{
		ctrl->format.data.whole_str[i--] =
				get_digit(whole->copy % whole->base, whole->is_upper);
		whole->copy /= whole->base;
	}
	whole->num_len = (FTP_STR_NUM_SIZE - i - 1);
}
