/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:16:26 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/30 11:09:53 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_GNL_H
# define LIBFT_GNL_H

# define SB_UNEXPECTED -4
# define SB_ERR_ALLOC -3
# define SB_ERR_FILE -2
# define SB_ERR_LAUNCH -1

# define SB_OUT_EOF 0
# define SB_OUT_MID 1

# define SB_IN_EOF 10
# define SB_IN_MID 11

# define SB_DEFAULT 20

# define SB_INIT 20
# define SB_MULT 3

# include "libft_standart.h"
# include "libft_list.h"

typedef struct		s_sb
{
	int				fd;
	int				size;
	char			*begin;
	char			*end;
	char			*out_begin;
	char			*out_end;
	char			*in;
	char			**target;
}					t_sb;

t_sb				*sb_alloc(int fd, int size, char **target);

void				sb_free(void *m);

int					sb_realloc(t_sb *sb, int new_size);

void				sb_reset(t_sb *sb);

int					sb_in(t_sb *sb, int bs);

int					sb_out(t_sb *sb);

void				sb_set_target(t_sb *sb, char **target);

int					sb_fd_cmp(const void *m1, const void *m2);

# define BUFF_SIZE	32000

int					gnl(int fd, char **line);

#endif
