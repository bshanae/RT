#include "gui_signal_x.h"

void				static_get_time(char *destination)
{
	time_t			time_raw;
	struct tm		*time_info;

	time (&time_raw);
	time_info = localtime(&time_raw);
	sprintf(destination, "RT Screen Shot %d-%2d-%02d at %2d.%2d.%2d",
			time_info->tm_year + 1900,
			time_info->tm_mday,
			time_info->tm_mon + 1,
			time_info->tm_hour,
			time_info->tm_min,
			time_info->tm_sec);
}

void				gui_signal_camera_screen_save
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;
	const char		*folder;
	char			time[64];
	char			path[128];

	gui = (t_gui *)ptr;
	static_get_time(time);
	ft_strcpy(path, RT_SOURCE_GUI_SCREENSHOTS);
	ft_strcat(path, time);
	ft_strcat(path, ".jpeg");
	if (gdk_pixbuf_save(gui->image->gdk_buffer, path, "jpeg", NULL, NULL))
	{
		gtk_dialog_run(gui->camera->screen_success);
		gtk_widget_hide(GTK_WIDGET(gui->camera->screen_success));
	}
	else
	{
		gtk_dialog_run(gui->camera->screen_fail);
		gtk_widget_hide(GTK_WIDGET(gui->camera->screen_fail));
	}
}

void				gui_signal_camera_screen_success_close
					(GtkWidget *w, gpointer p)
{
	t_gui			*gui;

	gui = (t_gui *)p;
	gtk_dialog_response(gui->camera->screen_success, GTK_RESPONSE_CANCEL);
}

void				gui_signal_camera_screen_fail_close
					(GtkWidget *w, gpointer p)
{
	t_gui			*gui;

	gui = (t_gui *)p;
	gtk_dialog_response(gui->camera->screen_fail, GTK_RESPONSE_CANCEL);
}