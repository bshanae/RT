/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_dancing_link.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 20:24:10 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/30 11:09:53 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_DANCING_LINK_H
# define LIBFT_DANCING_LINK_H

# include "libft_standart.h"
# include "libft_ft_printf.h"

typedef struct				s_dancing_link
{
	void					*data;
	struct s_dancing_link	*right;
	struct s_dancing_link	*upper;
	struct s_dancing_link	*left;
	struct s_dancing_link	*lower;
}							t_dancing_link;

t_dancing_link				*dancing_link_allocate
	(const void *data, long size);

t_dancing_link				*dancing_link_create
	(int i, int j, long size);

void						dancing_link_destroy
	(t_dancing_link **me);

void						dancing_link_remove
	(t_dancing_link **me);

void						dancing_link_print
		(t_dancing_link *me, void (*f)(void *data));

t_dancing_link				**dancing_link_at
	(t_dancing_link **me, int i, int j);

void						dancing_link_connect_hor
		(t_dancing_link **left, t_dancing_link **right);

void						dancing_link_connect_ver
		(t_dancing_link **upper, t_dancing_link **lower);

#endif
