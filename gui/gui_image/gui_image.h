/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_image.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:37:18 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/01 18:37:21 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_IMAGE_H
# define GUI_IMAGE_H

# include "rt_parameters.h"

# include "libft_standart.h"
# include "error_framework.h"
# include "color.h"

# include <gtk/gtk.h>

typedef struct		s_gui_image
{
	GtkEventBox		*event_box;
	GtkImage		*image;
	GdkPixbuf		*gdk_buffer;
	guchar			*char_buffer;
	t_color			*color_buffer;
	int				width;
	int				height;
	t_rt_bool		resize_request;
}					t_gui_image;

t_gui_image			*gui_image_new(GtkBuilder *builder);
void				gui_image_delete(t_gui_image **image);

void				gui_image_allocate(t_gui_image *image);

#endif
