#include "gui_settings.h"

void 				gui_settings_connect(t_gui_settings *settings, ...)
{
	va_list 		args;

	va_start(args, settings);
	settings->ptr_settings = va_arg(args, t_rt_settings *);
	va_end(args);
	settings->connected = rt_true;
}