/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 12:21:28 by sbosmer           #+#    #+#             */
/*   Updated: 2019/09/29 19:08:56 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#include "error_framework.h"

int					ft_strequ(char const *s1, char const *s2)
{
	if (!s1 || !s2)
		return (0);
	return (strcmp(s1, s2) ? 0 : 1);
}

int		ft_strnequ(char const *s1, char const *s2, size_t len)
{
	if (!s1 || !s2)
		return (0);
	return (strncmp(s1, s2, len) ? 0 : 1);
}

char				*read_file(const char *path)
{
	int		fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	lseek(fd, 0, SEEK_END);
	long	fsize = lseek(fd, 0, SEEK_CUR);
	lseek(fd, 0, SEEK_SET);
	
	char *string = rt_malloc(fsize + 1);
	if (!string)
		return (NULL);
	read(fd, string, fsize);
	close(fd);

	string[fsize] = 0;
	return (string);
}