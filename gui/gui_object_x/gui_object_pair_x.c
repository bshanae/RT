#include "gui_object_x.h"


t_gui_object_pair			gui_object_pair_init
							(t_gui_init_pair *init, GtkBuilder *builder)
{
	t_gui_object_pair		pair;

	pair.first = RT_GUI_GET(builder, init->first);
	pair.second = RT_GUI_GET(builder, init->second);
	return (pair);
}

void						gui_object_pair_get
	(t_gui_object_pair *gui, t_object *object)
{

}

void 						gui_object_pair_set
	(t_gui_object_pair *gui, t_object *object)
{

}