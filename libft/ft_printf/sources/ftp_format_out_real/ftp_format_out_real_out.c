/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_format_out_real_out.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 14:12:31 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/23 14:12:34 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ft_printf.h"

static int			out_whole(t_ftp_buffer *buff, t_real_params *real)
{
	int				i;
	char			*temp;

	i = real->whole.length - 1;
	while (i != -1)
	{
		if (!(temp = long_at(&real->whole.data, i--)))
			return (FTP_ERR_INTERNAL);
		buffer_custom_in_char(buff, '0' + *temp, 1);
	}
	return (0);
}

static int			out_fract
	(t_ftp_buffer *buff, t_real_params *real, int limit)
{
	int				i;
	char			*temp;

	if (limit || real->force_point)
		buffer_custom_in_char(buff, '.', 1);
	i = real->fract.length - 1;
	while (i != -1 && limit > 0)
	{
		if (!(temp = long_at(&real->fract.data, i--)))
			return (FTP_ERR_INTERNAL);
		buffer_custom_in_char(buff, '0' + *temp, 1);
		limit--;
	}
	while (limit > 0)
	{
		buffer_custom_in_char(buff, '0', 1);
		limit--;
	}
	return (0);
}

int					ftp_format_out_real_out
	(t_ftp_buffer *buff, t_real_params *real, int fract_limit)
{
	if (real->exception.is_present)
	{
		buffer_custom_in_str(buff, real->exception.data);
		return (0);
	}
	if (out_whole(buff, real) == FTP_ERR_INTERNAL)
		return (FTP_ERR_INTERNAL);
	if (out_fract(buff, real, fract_limit) == FTP_ERR_INTERNAL)
		return (FTP_ERR_INTERNAL);
	return (0);
}
