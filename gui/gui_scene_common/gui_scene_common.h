/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_common.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:38:49 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_SCENE_COMMON_H
# define GUI_SCENE_COMMON_H

# include "rt_parameters.h"

# include "scene.h"

# include <gtk/gtk.h>

typedef struct		s_gui_scene_common
{
	t_rt_bool		connected;
	t_scene			*ptr_scene;
	t_rt_light_mod	*ptr_light;
	GtkListStore	*full;
	GtkListStore	*limited_main;
	GtkListStore	*limited_limit;
	GtkListStore	*csg;
	GtkListStore	*types;
	GtkListStore	*textures;
	GtkListStore	*background;
	t_rt_bool		reset_generator;
	t_rt_bool		update_process;
}					t_gui_scene_common;

t_gui_scene_common	*gui_scene_common_new(GtkBuilder *builder);
void				gui_scene_common_connect(t_gui_scene_common *common, ...);
void				gui_scene_common_delete(t_gui_scene_common **common);

typedef enum		e_gui_scene_list_column
{
	gui_list_id,
	gui_list_name
}					t_gui_scene_list_column;

void				gui_scene_common_gen_name
					(t_gui_scene_common *scene, t_object *object);

void				gui_scene_common_add_to_list
					(GtkListStore *list, t_object *object);

int					gui_scene_common_check_mod
					(t_gui_scene_common *gui, t_object *object);

void				gui_scene_common_update_full
					(t_gui_scene_common *gui);
void				gui_scene_common_update_limited
					(t_gui_scene_common *gui);
void				gui_scene_common_update_csg
					(t_gui_scene_common *gui);
void				gui_scene_common_update_types
					(t_gui_scene_common *gui);
void				gui_scene_common_update_textures
					(t_gui_scene_common *gui);
void				gui_scene_common_update_background
					(t_gui_scene_common *gui);
void				gui_scene_common_update_all
					(t_gui_scene_common *gui);

typedef	void		(t_gui_scene_update_function)(t_gui_scene_common *gui);

void				gui_scene_common_update_wrap
					(t_gui_scene_common *gui,
					t_gui_scene_update_function *func);

void				gui_scene_common_update_full_wrapped
					(t_gui_scene_common *gui);
void				gui_scene_common_update_limited_wrapped
					(t_gui_scene_common *gui);
void				gui_scene_common_update_csg_wrapped
					(t_gui_scene_common *gui);
void				gui_scene_common_update_types_wrapped
					(t_gui_scene_common *gui);
void				gui_scene_common_update_textures_wrapped
					(t_gui_scene_common *gui);
void				gui_scene_common_update_background_wrapped
					(t_gui_scene_common *gui);
void				gui_scene_common_update_all_wrapped
					(t_gui_scene_common *gui);

#endif
