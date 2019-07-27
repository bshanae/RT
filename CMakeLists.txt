cmake_minimum_required(VERSION 3.14)
project(test_gui C)

set(GTK_INCLUDES_A
    /usr/local/Cellar/libffi/3.2.1/lib/libffi-3.2.1/include
    /usr/local/Cellar/gtk+3/3.24.10/include/gtk-3.0
    /usr/local/Cellar/glib/2.60.5/include/gio-unix-2.0
    /usr/local/Cellar/cairo/1.16.0_2/include/cairo
    /usr/local/Cellar/libepoxy/1.5.3/include
    /usr/local/Cellar/pango/1.42.4_2/include/pango-1.0
    /usr/local/Cellar/harfbuzz/2.5.3/include/harfbuzz
    /usr/local/Cellar/graphite2/1.3.13/include
    /usr/local/Cellar/pango/1.42.4_2/include/pango-1.0
    /usr/local/Cellar/fribidi/1.0.5/include/fribidi
    /usr/local/Cellar/atk/2.32.0_1/include/atk-1.0
    /usr/local/Cellar/cairo/1.16.0_2/include/cairo
    /usr/local/Cellar/pixman/0.38.4/include/pixman-1
    /usr/local/Cellar/fontconfig/2.13.1/include
    /usr/local/opt/freetype/include/freetype2
    /usr/local/Cellar/libpng/1.6.37/include/libpng16
    /usr/local/Cellar/gdk-pixbuf/2.38.1_1/include/gdk-pixbuf-2.0
    /usr/local/Cellar/glib/2.60.5/include
    /usr/local/Cellar/glib/2.60.5/include/glib-2.0
    /usr/local/Cellar/glib/2.60.5/lib/glib-2.0/include
    /usr/local/opt/gettext/include
    /usr/local/Cellar/pcre/8.43/include)

set(GTK_LINKS_A
	/usr/local/Cellar/gtk+3/3.24.10/lib
	/usr/local/Cellar/pango/1.42.4_2/lib
	/usr/local/Cellar/atk/2.32.0_1/lib
	/usr/local/Cellar/cairo/1.16.0_2/lib
	/usr/local/Cellar/gdk-pixbuf/2.38.1_1/lib
	/usr/local/Cellar/glib/2.60.5/lib
	/usr/local/opt/gettext/lib)

set(GTK_INCLUDES_B
	/Users/bshanae/.brew/Cellar/libffi/3.2.1/lib/libffi-3.2.1/include
	/Users/bshanae/.brew/Cellar/gtk+3/3.24.10/include/gtk-3.0
	/Users/bshanae/.brew/Cellar/glib/2.60.6/include/gio-unix-2.0
	/Users/bshanae/.brew/Cellar/cairo/1.16.0_2/include/cairo
	/Users/bshanae/.brew/Cellar/libepoxy/1.5.3/include
	/Users/bshanae/.brew/Cellar/pango/1.42.4_2/include/pango-1.0
	/Users/bshanae/.brew/Cellar/harfbuzz/2.5.3/include/harfbuzz
	/Users/bshanae/.brew/Cellar/graphite2/1.3.13/include
	/Users/bshanae/.brew/Cellar/pango/1.42.4_2/include/pango-1.0
	/Users/bshanae/.brew/Cellar/fribidi/1.0.5/include/fribidi
	/Users/bshanae/.brew/Cellar/atk/2.32.0_1/include/atk-1.0
	/Users/bshanae/.brew/Cellar/cairo/1.16.0_2/include/cair
	/Users/bshanae/.brew/Cellar/pixman/0.38.4/include/pixman-1
	/Users/bshanae/.brew/Cellar/fontconfig/2.13.1/include
	/Users/bshanae/.brew/opt/freetype/include/freetype2
	/Users/bshanae/.brew/Cellar/libpng/1.6.37/include/libpng16
	/Users/bshanae/.brew/Cellar/gdk-pixbuf/2.38.1_1/include/gdk-pixbuf-2.0
	/Users/bshanae/.brew/Cellar/glib/2.60.6/include
	/Users/bshanae/.brew/Cellar/glib/2.60.6/include/glib-2.0
	/Users/bshanae/.brew/Cellar/glib/2.60.6/lib/glib-2.0/include
	/Users/bshanae/.brew/opt/gettext/include
	/Users/bshanae/.brew/Cellar/pcre/8.43/include)

set(GTK_LINKS_B
	/Users/bshanae/.brew/Cellar/gtk+3/3.24.10/lib
	/Users/bshanae/.brew/Cellar/pango/1.42.4_2/lib
	/Users/bshanae/.brew/Cellar/atk/2.32.0_1/lib
	/Users/bshanae/.brew/Cellar/cairo/1.16.0_2/lib
	/Users/bshanae/.brew/Cellar/gdk-pixbuf/2.38.1_1/lib
	/Users/bshanae/.brew/Cellar/glib/2.60.6/lib
	/Users/bshanae/.brew/opt/gettext/lib)

link_directories(
	../21_libft/
	${GTK_LINKS_A})

link_libraries(
    "ft"
    "gtk-3"
    "gdk-3"
    "pangocairo-1.0"
    "pango-1.0"
    "atk-1.0"
    "cairo-gobject"
    "cairo"
    "gdk_pixbuf-2.0"
    "gio-2.0"
    "gobject-2.0"
    "glib-2.0"
    "intl"
    "-framework Cocoa"
    "-framework Carbon"
    "-framework CoreGraphics")

include_directories(
    ../21_libft/includes
    ${GTK_INCLUDES_A})

add_executable(test_gui
    main.c)

