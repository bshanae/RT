/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_connect_ver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 20:10:02 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/05 20:23:33 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_dancing_link.h"

void						dancing_link_connect_ver
	(t_dancing_link **upper, t_dancing_link **lower)
{
	if (!upper || !lower)
		return ;
	if (*upper)
		(*upper)->lower = *lower;
	if (*lower)
		(*lower)->upper = *upper;
}
