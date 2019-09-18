#include "gui_queue.h"

void 				gui_queue_wait(t_gui_queue *queue)
{
	double 			start;
	double 			current;

	start = gui_queue_get_time();
	while (!queue->force_finished)
	{
		current = gui_queue_get_time();
		if (current - start > RT_GUI_QUEUE_WAIT_LIMIT)
			break ;
	}
}