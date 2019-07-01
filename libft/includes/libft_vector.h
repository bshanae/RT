/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:15:25 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/30 11:09:53 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_VECTOR_H
# define LIBFT_VECTOR_H

# include "libft_standart.h"

# define VECTOR_ALLOC_INIT	10
# define VECTOR_ALLOC_MULT	2
# define VECTOR_ALLOC_LIMIT	0.5

typedef struct				s_vector
{
	void					*storage;
	size_t					element_size;
	size_t					capacity;
	size_t					length;
}							t_vector;

t_vector					vector_create(size_t element_size);

void						vector_destroy(t_vector *me);

void						vector_resize(t_vector *me, size_t capacity);

void						*vector_at(t_vector *me, size_t index);

void						*vector_push_back(t_vector *me, void *data);

void						*vector_emplace_back(t_vector *me, ...);

void						vector_pop_back(t_vector *me);

void						vector_insert
	(t_vector *me, size_t i_dest, void *data);

void						vector_erase(t_vector *me, size_t index);

void						vector_clear(t_vector *me);

void						vector_print
	(t_vector *me, void (*f)(const void *));

void						*vector_find
	(t_vector *me, const void *ptr, int (*cmp)(const void *, const void *));

#endif
