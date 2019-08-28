#include "gui_queue.h"

void				gui_queue_finish(t_gui_queue *queue)
{
	queue->block = 1;
	queue->kill_timeout = 1;
}
