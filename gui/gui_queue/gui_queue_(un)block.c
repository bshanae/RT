#include "gui_queue.h"

void 				gui_queue_block(t_gui_queue *queue)
{
	double 			start;
	double 			current;

	queue->block_last_state = queue->block;
	queue->block = 1;
	start = gui_queue_get_time();
	while (!queue->free)
	{
		current = gui_queue_get_time();
		if (current - start > RT_GUI_QUEUE_WAIT_LIMIT)
			break ;
	}
	printf("Queue blocked\n");
}

void 				gui_queue_unblock(t_gui_queue *queue)
{
	queue->block = queue->block_last_state;
	printf("Queue unblocked\n\n");
}