/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:16:32 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/30 11:09:53 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_BTREE_H
# define LIBFT_BTREE_H

# include "libft_standart.h"

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*content;
}					t_btree;

t_btree				*btree_alloc(const void *content, size_t content_size);

void				btree_clean(t_btree **root, void (*del)(void *));

t_btree				*btree_insert
	(t_btree **root, const void *content, size_t content_size,
	int (*cmpf)(const void *, const void *));

t_btree				*btree_delete
	(t_btree **root, const void *content,
	int (*cmpf)(const void *, const void *), void (*del)(void *));

t_btree				*btree_find
					(t_btree **root, const void *content,
					int (*cmpf)(const void *, const void *));

int					btree_depth(t_btree **root);

int					btree_verify
	(t_btree **root, int (*cmpf)(const void *, const void *));

void				btree_prefix(t_btree *root, void (*f)(void *));

void				btree_infix(t_btree *root, void (*f)(void *));

void				btree_suffix(t_btree *root, void (*f)(void *));

#endif
