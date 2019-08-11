#ifndef GUI_SIGNAL_CONNECT_MACRO_H
# define GUI_SIGNAL_CONNECT_MACRO_H

# define GTK_ADD_CALLBACK	gtk_builder_add_callback_symbol
# define GUI_CONNECT(b, s)	GTK_ADD_CALLBACK(gui->builder, #s, G_CALLBACK(s));

#endif
