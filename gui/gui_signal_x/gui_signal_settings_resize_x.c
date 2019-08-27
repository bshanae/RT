#include "gui_signal_x.h"

void 				gui_signal_settings_resize_open
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gtk_image_clear(gui->image->image);
	gui_entry_set_i(gui->settings->resize_width, gui->image->width);
	gui_entry_set_i(gui->settings->resize_height, gui->image->height);
	gtk_window_set_resizable(gui->window, TRUE);
}

void 				gui_signal_settings_resize_save
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gtk_window_set_resizable(gui->window, FALSE);
	gtk_popover_popdown(gui->settings->resize_popover);
}

void 				gui_signal_settings_resize_auto
					(GtkWidget *widget, GdkRectangle *allocation, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gui->image->width = allocation->width;
	gui->image->height = allocation->height;
	gui_entry_set_i(gui->settings->resize_width, gui->image->width);
	gui_entry_set_i(gui->settings->resize_height, gui->image->height);
//	gui->image->gdk_buffer = gdk_pixbuf_new(GDK_COLORSPACE_RGB, TRUE, 8, gui->image->width, gui->image->height);
//	gtk_image_set_from_pixbuf(gui->image->image, gui->image->gdk_buffer);
//	gui->image->char_buffer = gdk_pixbuf_get_pixels(gui->image->gdk_buffer);
//	gui->image->color_buffer = (t_color *)gui->image->char_buffer;
//	for (int i = 0; i < gui->image->width * gui->image->height; i++)
//		gui->image->color_buffer[i] = (t_color){0, 0, 0, 255};
//	gtk_image_set_from_pixbuf(gui->image->image, gui->image->gdk_buffer);
}

void				gui_signal_settings_resize_manual_width
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;
	int 			value;
	GtkAllocation	allocation;

	gui = (t_gui *)ptr;
	value = gui_entry_get_i(gui->settings->resize_width);
	if (value < 1 || value > 2560)
		return ;
	gui->image->width = value;
//	gtk_widget_set_size_request(GTK_WIDGET(gui->image->image),
//		gui->image->width, gui->image->height);
	allocation.width = gui->image->width;
	allocation.height = gui->image->height;
	gtk_widget_size_allocate(GTK_WIDGET(gui->image->image), &allocation);
	gtk_widget_show(GTK_WIDGET(gui->image->image));
}

void				gui_signal_settings_resize_manual_height
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;
	int 			value;

	gui = (t_gui *)ptr;
	value = gui_entry_get_i(gui->settings->resize_height);
	if (value < 1 || value > 2560)
		return ;
	gui->image->height = value;
	gtk_widget_set_size_request(GTK_WIDGET(gui->image->image),
		gui->image->width, gui->image->height);
	gtk_widget_show(GTK_WIDGET(gui->image->image));
}
