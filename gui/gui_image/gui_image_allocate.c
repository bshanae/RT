/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_image_allocate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:37:43 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/01 18:38:30 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_image.h"

void				gui_image_allocate(t_gui_image *image)
{
	int				i;

	if (image->gdk_buffer)
		g_object_unref(image->gdk_buffer);
	image->gdk_buffer = gdk_pixbuf_new(GDK_COLORSPACE_RGB,
		TRUE, 8, image->width, image->height);
	image->char_buffer = gdk_pixbuf_get_pixels(image->gdk_buffer);
	image->color_buffer = (t_color *)image->char_buffer;
	i = 0;
	while (i < image->width * image->height)
		image->color_buffer[i++] = (t_color){0, 0, 0, 255};
	gtk_image_set_from_pixbuf(image->image, image->gdk_buffer);
}
