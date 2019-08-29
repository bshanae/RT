#ifndef GUI_SIGNAL_CONNECT_MACRO_H
# define GUI_SIGNAL_CONNECT_MACRO_H

# define GTK_ADD_CALLBACK		gtk_builder_add_callback_symbol
# define RT_GUI_CONNECT(g, s)	GTK_ADD_CALLBACK(g->builder, #s, G_CALLBACK(s))

#endif
