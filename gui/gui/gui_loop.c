#include "gui.h"

void				gui_loop(t_gui *gui)
{
	GtkAllocation allocation;
	gtk_widget_get_allocation(GTK_WIDGET(gui->image->event_box), &allocation);
	printf("%d %d\n", allocation.width, allocation.height);

	gui_queue_start(gui->queue);
	gtk_main();
}