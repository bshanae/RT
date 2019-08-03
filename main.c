#include "gui.h"

int					main(int argc, char **argv)
{
	t_gui			*gui;

	gui = gui_new();
	gui_init(gui, &argc, &argv);
	gui_start(gui);
	return (0);
}