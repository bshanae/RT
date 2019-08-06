cmake_minimum_required(VERSION 3.14)
project(rt C)

set(CMAKE_CFLAGS "${CMAKE_CFALGS} -Wall -Wextra")

set(GTK_INCLUDES
	/Users/bshanae/.brew/Cellar/libffi/3.2.1/lib/libffi-3.2.1/include
	/Users/bshanae/.brew/Cellar/gtk+3/3.24.10/include/gtk-3.0/
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

set(GTK_LINKS
	/Users/bshanae/.brew/Cellar/gtk+3/3.24.10/lib
	/Users/bshanae/.brew/Cellar/pango/1.42.4_2/lib
	/Users/bshanae/.brew/Cellar/atk/2.32.0_1/lib
	/Users/bshanae/.brew/Cellar/cairo/1.16.0_2/lib
	/Users/bshanae/.brew/Cellar/gdk-pixbuf/2.38.1_1/lib
	/Users/bshanae/.brew/Cellar/glib/2.60.6/lib
	/Users/bshanae/.brew/opt/gettext/lib)


include_directories(
	${GTK_INCLUDES}
	../21_libft/includes/
	./
	./gui/
	./gui/gui/
	./gui/gui_scene/
	./gui/gui_object/
	./gui/gui_object_base/
	./gui/gui_list/
	./gui/gui_image/
	./gui/gui_signal/
	./color/
	./vector3/
	./light/
	./object/
	./object_list/
	./scene/
	cl_renderer/
	./camera/
	./ray/
	./intersection/
	./ft_assert/
	./open_cl_manager/)

link_directories(
	${GTK_LINKS}
	../21_libft/)

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
	"-framework CoreGraphics"
	"-framework OpenCL")

set(SOURCE_MAIN
	./main.c)

set(SOURCE_GUI_GUI
	./gui/gui/gui_new.c
	./gui/gui/gui_delete.c
	./gui/gui/gui_connect_renderer.c
	./gui/gui/gui_loop.c)

set(SOURCE_GUI_LIST
	./gui/gui_list/gui_list_new.c
	./gui/gui_list/gui_list_delete.c)

set(SOURCE_GUI_OBJECT
	./gui/gui_object/gui_object_new.c
	./gui/gui_object/gui_object_delete.c
	./gui/gui_object_base/gui_object_base_init.c
	./gui/gui_object_list/gui_object_sphere.c
	./gui/gui_object_list/gui_object_plane.c)

set(SOURCE_GUI_IMAGE
	./gui/gui_image/gui_image_new.c
	./gui/gui_image/gui_image_delete.c)

set(SOURCE_GUI_SIGNAL
	./gui/gui_signal/gui_signal_connect.c
	./gui/gui_signal/gui_s_obj_selected.c
	./gui/gui_signal/gui_s_sphere_pos.c
	./gui/gui_signal/gui_s_key.c
	./gui/gui_signal/gui_s_sphere_rad.c
	./gui/gui_signal/gui_s_plane_pos.c
	./gui/gui_signal/gui_s_plane_norm.c
	./gui/gui_signal/gui_s_obj_add.c)

set(SOURCE_GUI
	${SOURCE_GUI_GUI}
	${SOURCE_GUI_LIST}
	${SOURCE_GUI_OBJECT}
	${SOURCE_GUI_IMAGE}
	${SOURCE_GUI_SIGNAL})

set(SOURCE_VECTOR3
	./vector3/vector3_add.c
	./vector3/vector3_sub.c
	./vector3/vector3_mul.c
	./vector3/vector3_div.c
	./vector3/vector3_dot.c
	./vector3/vector3_cross.c
	./vector3/vector3_length.c
	./vector3/vector3_normal.c
	./vector3/vector3_max.c
	./vector3/vector3_min.c
	./vector3/vector3_component_mul.c)

set(SOURCE_CL_RENDERER
	./cl_renderer/cl_renderer_new.c
	./cl_renderer/cl_renderer_delete.c
	./cl_renderer/cl_renderer_init_device.c
	./cl_renderer/cl_renderer_init_context.c
	./cl_renderer/cl_renderer_create_program.c
	./cl_renderer/cl_renderer_create_queue.c
	./cl_renderer/cl_renderer_create_kernel.c
	./cl_renderer/cl_renderer_init_data.c
	./cl_renderer/cl_renderer_set_arguments.c
	./cl_renderer/cl_renderer_render.c
	cl_renderer/cl_renderer_log.c)

set(SOURCE_SCENE
	./scene/scene_new.c
	./scene/scene_get_space.c
	./scene/scene_delete.c
	./scene/scene_intersect.c)

set(SOURCE_OBJECT
	./object/object_build.c
	./object_list/sphere.c
	./object/object_intersect.c
	./object_list/plane.c
	./gui/gui_signal/gui_s_key.c)

set(SOURCE_CAMERA
	./camera/camera_new.c
	./camera/camera_delete.c
	./camera/camera_build_ray.c)

set(SOURCE_FT_ASSERT
	./ft_assert/ft_assert.c)

set(SOURCE_RAY
	./ray/ray)

add_executable(rt
	${SOURCE_MAIN}
	${SOURCE_GUI}
	${SOURCE_VECTOR3}
	${SOURCE_CL_RENDERER}
	${SOURCE_SCENE}
	${SOURCE_OBJECT}
	${SOURCE_CAMERA}
	${SOURCE_FT_ASSERT})