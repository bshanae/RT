/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_queue.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 20:22:27 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/30 11:09:53 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_QUEUE_H
# define LIBFT_QUEUE_H

# include "libft_standart.h"
# include "libft_ft_printf.h"

typedef struct				s_queue_piece
{
	void					*data;
	struct s_queue_piece	*next;
}							t_queue_piece;

typedef struct				s_queue
{
	t_queue_piece			*begin;
	t_queue_piece			*end;
	long					data_size;
	long					length;
}							t_queue;

void						queue_error(t_queue *me);

t_queue						queue_create(long data_size);

void						queue_destroy(t_queue *me);

void						queue_pop(t_queue *me);

void						queue_push(t_queue *me, void *data);

void						*queue_front(t_queue *me);

void						*queue_back(t_queue *me);

void						queue_print(t_queue *me, void (*f)(void *));

#endif
