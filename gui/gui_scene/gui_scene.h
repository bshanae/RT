/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:14:57 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/02 16:15:00 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_SCENE_H
# define GUI_SCENE_H

# include "gui_scene_common.h"
# include "gui_scene_edit.h"
# include "gui_scene_add.h"

# include <gtk/gtk.h>

typedef struct				s_gui_scene
{
	t_gui_scene_common		*common;
	t_gui_scene_edit		*edit;
	t_gui_scene_add			*add;
}							t_gui_scene;

t_gui_scene					*gui_scene_new(GtkBuilder *builder);
void						gui_scene_delete(t_gui_scene **scene);

#endif
