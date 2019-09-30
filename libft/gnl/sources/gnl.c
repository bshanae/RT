/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 19:58:09 by bshanae           #+#    #+#             */
/*   Updated: 2019/04/26 21:54:23 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_gnl.h"

int					gnl(int fd, char **line)
{
	static t_list	*store;
	t_list			*temp_list;
	t_sb			*temp_sb;
	int				code[2];

	if (fd < 0 || BUFF_SIZE < 1 || !line)
		return (SB_ERR_LAUNCH);
	temp_list = list_find(&store, (void *)&fd, sb_fd_cmp);
	if (!temp_list)
	{
		if (!(temp_sb = sb_alloc(fd, ft_max(BUFF_SIZE + 1, SB_INIT), NULL)))
			return (SB_ERR_ALLOC);
		temp_list = list_emplace_back(&store, &temp_sb, sizeof(t_sb *));
	}
	sb_set_target(*(t_sb **)(temp_list->content), line);
	code[0] = sb_in(*(t_sb **)(temp_list->content), BUFF_SIZE);
	if (code[0] < 0)
		return (code[0]);
	code[1] = sb_out(*(t_sb **)(temp_list->content));
	if (code[1] < 0)
		return (code[1]);
	if (code[0] == SB_IN_EOF)
		list_delete(&store, temp_list, NULL, sb_free);
	return (code[1]);
}
