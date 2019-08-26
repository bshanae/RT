/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:14:17 by sbosmer           #+#    #+#             */
/*   Updated: 2019/08/26 16:16:13 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json.h"
#include "json_parse.h"
#include "cl_renderer.h"

void	renderer_load(t_cl_renderer *renderer, char *path)
{
	load_scene(renderer, path);
}
