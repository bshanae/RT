#include "gui_queue.h"

t_gui_queue			*gui_queue_new(void *data, void (*function)(void *))
{
	t_gui_queue		*new;

	printf("GUI : Initializing thread queue\n");
	new = (t_gui_queue *)rt_malloc(sizeof(t_gui_queue));
	new->pool = g_thread_pool_new((FUNC_MASK)gui_queue_execute,
		new, 1, FALSE, NULL);
	new->master_data = data;
	new->master_function = function;
	new->free = 1;
	new->block = 0;
	new->kill_timeout = 0;
	new->force_execute = 1;
	new->force_finished = 0;
	new->pass = 0;
	return (new);
}
