/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:16:38 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/30 11:09:53 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_LIST_H
# define LIBFT_LIST_H

# include "libft_standart.h"

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*list_alloc(void const *content, size_t content_size);

void				list_free(t_list **alst, void (*del)(void *));

void				list_clean(t_list **alst, void (*del)(void *));

t_list				*list_push_front(t_list **alst, t_list *new);

t_list				*list_push_back(t_list **alst, t_list *new);

t_list				*list_emplace_front
	(t_list **alst, void const *content, size_t content_size);

t_list				*list_emplace_back
	(t_list **alst, void const *content, size_t content_size);

t_list				*list_delete
	(t_list **alst, const void *content,
	int (*cmp)(const void *, const void *), void (*del)(void *));

t_list				*list_find
	(t_list **alst, const void *content,
	int (*cmp)(const void *, const void *));

void				list_iter(t_list *lst, void (*f)(t_list *elem));

void				list_print
(t_list **alst, void (*print)(const void *content));

t_list				*list_last(t_list **lst);

int					list_len(t_list **lst);

#endif
