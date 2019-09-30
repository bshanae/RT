/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreeclean.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:19:56 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/07 18:10:03 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_btree.h"

static void		replace(t_btree **main, t_btree **new, void (*del)(void *))
{
	del((*main)->content);
	free(*main);
	*main = new ? *new : NULL;
}

static void		swap_content(t_btree *a, t_btree *b)
{
	void		*temp;

	temp = a->content;
	a->content = b->content;
	b->content = temp;
}

static t_btree	**find_replace(t_btree *root)
{
	t_btree		*temp;

	if (!(root->right->left))
		return (&(root->right));
	temp = root->right;
	while (temp->left->left)
		temp = temp->left;
	return (&(temp->left));
}

t_btree			*btree_delete
	(t_btree **root, const void *content,
	int (*cmpf)(const void *, const void *), void (*del)(void *))
{
	int			cmp_root;
	t_btree		**temp;

	if (!root || !*root || !cmpf)
		return (NULL);
	cmp_root = cmpf(content, (*root)->content);
	if (cmp_root < 0)
		return (btree_delete(&((*root)->left), content, cmpf, del));
	if (cmp_root > 0)
		return (btree_delete(&((*root)->right), content, cmpf, del));
	if ((*root)->left && (*root)->right)
	{
		temp = find_replace(*root);
		swap_content(*root, *temp);
		btree_delete(temp, content, cmpf, del);
	}
	else if ((*root)->left)
		replace(root, &((*root)->left), del);
	else if ((*root)->right)
		replace(root, &((*root)->right), del);
	else
		replace(root, NULL, del);
	return (*root);
}
