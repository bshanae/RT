#ifndef GUI_QUEUE_H
# define GUI_QUEUE_H

# include "rt_parameters.h"

# include <gtk/gtk.h>

# define FUNC_MASK	void(*)(void *, void *)

typedef struct 		s_gui_queue
{
	GThreadPool		*pool;
	void 			*master_data;
	void 			(*master_function)(void *ptr);
	int 			block;
	int 			block_last_state;
	int 			kill_timeout;
	int 			force_execute;
	int 			wait;
}					t_gui_queue;

t_gui_queue			*gui_queue_new(void *data, void (*function)(void *ptr));
void 				gui_queue_delete(t_gui_queue **queue);

void				gui_queue_start(t_gui_queue *queue);
void				gui_queue_finish(t_gui_queue *queue);
void				gui_queue_block(t_gui_queue *queue);
void				gui_queue_unblock(t_gui_queue *queue);
gboolean			gui_queue_push(t_gui_queue *queue);
void				gui_queue_execute(void *ptr, t_gui_queue *queue);
void				gui_queue_execute_force(t_gui_queue *queue);

#endif
