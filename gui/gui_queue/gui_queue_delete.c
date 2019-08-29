#include "gui_queue.h"

void 				gui_queue_delete(t_gui_queue **queue)
{
	g_thread_pool_free((*queue)->pool, TRUE, TRUE);
	free(*queue);
	*queue = NULL;
}
