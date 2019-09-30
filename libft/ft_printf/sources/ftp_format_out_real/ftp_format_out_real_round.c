/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_format_out_real_round.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 14:10:03 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/23 14:10:03 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ft_printf.h"

static void			round_apply
	(t_real_params *real, t_round_type round, int fract_limit)
{
	int				i;
	int				temp;

	if (!fract_limit)
	{
		if (round == round_to_even && (*long_at(&real->whole.data, 0) % 2))
			long_add(&real->whole.data, 1);
		else if (round == round_up)
			long_add(&real->whole.data, 1);
		return ;
	}
	i = real->fract.length - fract_limit;
	temp = round == round_to_even ? *long_at(&real->fract.data, i) % 2 : 1;
	while (temp && i < real->fract.length)
	{
		temp += *long_at(&real->fract.data, i);
		*long_at(&real->fract.data, i) = temp % 10;
		temp /= 10;
		i++;
	}
	if (temp)
		long_add(&real->whole.data, 1);
}

void				ftp_format_out_real_round
	(t_real_params *real, int fract_limit)
{
	int				i;
	t_round_type	round;

	if (fract_limit > real->fract.length || !real->fract.length)
		return ;
	i = real->fract.length - fract_limit;
	if (i - 1 > -1 && *long_at(&real->fract.data, i - 1) < 5)
		round = round_down;
	else if (i - 1 > -1 && *long_at(&real->fract.data, i - 1) > 5)
		round = round_up;
	else
	{
		i -= 2;
		while (i != -1 && !*long_at(&real->fract.data, i))
			i--;
		round = i == -1 ? round_to_even : round_up;
	}
	if (round != round_down)
		round_apply(real, round, fract_limit);
	real->whole.length = real->whole.data.length;
	real->fract.length = real->fract.data.length - 1;
}
