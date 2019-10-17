/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 12:21:28 by sbosmer           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#include "error_framework.h"
#include "libft_gnl.h"

int					ft_strequ(char const *s1, char const *s2)
{
	if (!s1 || !s2)
		return (0);
	return (strcmp(s1, s2) ? 0 : 1);
}

char				*read_file(const char *path)
{
	int		fd;
	char	*line;
	char	*res;
	char	*old_res;

	res = ft_strnew(1);
	line = NULL;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while (gnl(fd, &line) > 0)
	{
		old_res = res;
		res = ft_strjoin(res, line);
		free(old_res);
		old_res = res;
		res = ft_strjoin(res, "\n");
		free(old_res);
		free(line);
	}
	close(fd);
	return (res);
}
