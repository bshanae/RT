#include "gui_queue.h"

gboolean			gui_queue_push(t_gui_queue *queue)
{
#ifdef RT_QUEUE_AUTO
	if (queue->kill_timeout)
		return (FALSE);
	g_thread_pool_push(queue->pool, queue, NULL);
	return (TRUE);
#else
	return (FALSE);
#endif
}
