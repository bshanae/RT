#include "gui_queue.h"

t_gui_queue			*gui_queue_new(void *data, void (*function)(void *ptr))
{
	t_gui_queue		*new;

	new = (t_gui_queue *)malloc(sizeof(t_gui_queue));
	new->pool = g_thread_pool_new((FUNC_MASK) gui_queue_execute_normal,
								  new, 1, FALSE, NULL);
	new->master_data = data;
	new->master_function = function;
	new->block = 0;
	new->kill_timeout = 0;
	return (new);
}
