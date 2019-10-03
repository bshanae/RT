/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_signal_camera_screen_x.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:28:41 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/03 13:28:55 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_signal_x.h"

void				static_get_time(char *destination)
{
	time_t			time_raw;
	struct tm		*time_info;

	time(&time_raw);
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
	char			time[64];
	char			path[128];

	gui = (t_gui *)ptr;
	static_get_time(time);
	ft_strcpy(path, RT_SOURCE_GUI_SCREENSHOTS);
	ft_strcat(path, time);
	ft_strcat(path, ".jpeg");
	if (gdk_pixbuf_save(gui->image->gdk_buffer, path, "jpeg", NULL, NULL))
	{
		gtk_label_set_text(gui->camera->screen_label,
			"Screenshot has been saved");
		gtk_dialog_run(gui->camera->screen_dialog);
		gtk_widget_hide(GTK_WIDGET(gui->camera->screen_dialog));
	}
	else
	{
		gtk_label_set_text(gui->camera->screen_label, "Error occured!");
		gtk_dialog_run(gui->camera->screen_dialog);
		gtk_widget_hide(GTK_WIDGET(gui->camera->screen_dialog));
	}
}

void				gui_signal_camera_screen_dialog_response
	(GtkWidget *w, gpointer p)
{
	t_gui			*gui;

	gui = (t_gui *)p;
	gtk_dialog_response(gui->camera->screen_dialog, GTK_RESPONSE_CANCEL);
}
