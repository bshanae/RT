#include "gui_queue.h"

void 				gui_queue_wait(t_gui_queue *queue)
{
	double 			start;
	double 			current;

	start = gui_queue_get_time();

	int i = 0;

	while (!queue->force_finished)
	{
		if (++i == 1000)
		{
			printf("Await iteration\n");
			i = 0;
		}

		current = gui_queue_get_time();
		if (current - start > RT_GUI_QUEUE_WAIT_LIMIT)
			break ;
	}
}