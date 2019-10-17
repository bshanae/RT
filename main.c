#include "gui.h"
#include "gui_signal_connect_x.h"

int					main(int argc, char **argv)
{
	t_gui			*gui;

	gui = gui_new(&argc, &argv);
	gui_signal_connect_all(gui);
	gui->renderer = cl_renderer_new(gui->image);
	cl_renderer_load(gui->renderer, "./scenes/cornell.json");
    gui_connect(gui);
	gui_update(gui);
	gui_loop(gui);
	gui_delete(&gui);
	return (0);
}
