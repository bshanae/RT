#include "gui_queue.h"

gboolean			gui_queue_push(t_gui_queue *queue)
{
	if (queue->kill_timeout)
		return (FALSE);
	g_thread_pool_push(queue->pool, queue, NULL);
	return (TRUE);
}
