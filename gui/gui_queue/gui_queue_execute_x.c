#include "gui_queue.h"

void				gui_queue_execute_normal(void *ptr, t_gui_queue *queue)
{
	if (g_thread_pool_unprocessed(queue->pool) > RT_GUI_QUEUE_CEILING)
		return ;
	if (queue->block)
		return ;
	queue->master_function(queue->master_data);
}

void				gui_queue_execute_force(void *ptr, t_gui_queue *queue)
{
	queue->master_function(queue->master_data);
}