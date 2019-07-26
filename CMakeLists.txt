cmake_minimum_required(VERSION 3.14)
project(test_gui C)

set(GTK_INCLUDES
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

link_directories(
    ../21_libft/
    /usr/local/Cellar/gtk+3/3.24.10/lib
    /usr/local/Cellar/pango/1.42.4_2/lib
    /usr/local/Cellar/atk/2.32.0_1/lib
    /usr/local/Cellar/cairo/1.16.0_2/lib
    /usr/local/Cellar/gdk-pixbuf/2.38.1_1/lib
    /usr/local/Cellar/glib/2.60.5/lib
    /usr/local/opt/gettext/lib)

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
    ${GTK_INCLUDES})

add_executable(test_gui
    main.c)

