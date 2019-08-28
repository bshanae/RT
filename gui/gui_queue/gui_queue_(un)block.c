#include "gui_queue.h"

void 				gui_queue_block(t_gui_queue *queue)
{
	queue->block_last_state = queue->block;
	queue->block = 1;
}

void 				gui_queue_unblock(t_gui_queue *queue)
{
	queue->block = queue->block_last_state;
}