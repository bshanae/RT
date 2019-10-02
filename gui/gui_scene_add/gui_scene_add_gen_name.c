/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_add_gen_name.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:25:40 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/02 16:25:55 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene_add.h"

char				*gui_scene_add_gen_name(t_gui_scene_add *add)
{
	char			*result;
	char			*temp;

	result = rt_malloc(32);
	ft_strcpy(result, "New object no. ");
	temp = ft_itoa(add->generator_next_id);
	ft_strcat(result, temp);
	free(temp);
	return (result);
}
