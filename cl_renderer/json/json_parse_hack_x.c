/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_parse_hack_x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:51:32 by ashari            #+#    #+#             */
/*   Updated: 2019/10/17 10:51:35 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json_parse.h"
#include "cl_renderer.h"

void	parse_hack_0(t_obj *box, void *data, char *json, jsmntok_t *tokens)
{
	t_rt_background	bg;

	box->val_s1 = get_string_in_object(json, tokens, "background");
	if (!box->val_s1)
		return ;
	if (ft_strequ(box->val_s1, "none"))
		bg = rt_background_none;
	else if (ft_strequ(box->val_s1, "one"))
		bg = rt_background_one;
	else if (ft_strequ(box->val_s1, "interpolated"))
		bg = rt_background_interpolation;
	else
		return ;
	cl_renderer_change_background(data, bg);
	free_box(box);
}

void	parse_hack_1(t_obj *box, void *data, char *json, jsmntok_t *tokens)
{
	t_rt_light_mod	light_mod;

	box->val_s1 = get_string_in_object(json, tokens, "light mod");
	if (!box->val_s1)
		return ;
	if (ft_strequ(box->val_s1, "basic"))
		light_mod = rt_light_basic;
	else if (ft_strequ(box->val_s1, "area"))
		light_mod = rt_light_area;
	else
		return ;
	cl_renderer_change_light_mod(data, light_mod);
	free_box(box);
}
