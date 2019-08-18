cmake_minimum_required(VERSION 3.14)
project(rt C)

find_package(PkgConfig REQUIRED)
#pkg_check_modules(GTK3 REQUIRED gtk+3)

set(BREW ~/.brew)

set(GTK_INCLUDES
		${BREW}/Cellar/gtk+3/3.24.10/include/gtk-3.0
		${BREW}/Cellar/libffi/3.2.1/lib/libffi-3.2.1/include
		${BREW}/Cellar/glib/2.60.6/include/gio-unix-2.0
		${BREW}/Cellar/cairo/1.16.0_2/include/cairo
		${BREW}/Cellar/libepoxy/1.5.3/include
		${BREW}/Cellar/pango/1.44.5/include/pango-1.0
		${BREW}/Cellar/fribidi/1.0.5/include/fribidi
		${BREW}/Cellar/harfbuzz/2.5.3/include/harfbuzz
		${BREW}/Cellar/graphite2/1.3.13/include
		${BREW}/Cellar/atk/2.32.0_1/include/atk-1.0
		${BREW}/Cellar/cairo/1.16.0_2/include/cairo
		${BREW}/Cellar/pixman/0.38.4/include/pixman-1
		${BREW}/Cellar/fontconfig/2.13.1/include
		${BREW}/opt/freetype/include/freetype2
		${BREW}/Cellar/libpng/1.6.37/include/libpng16
		${BREW}/Cellar/gdk-pixbuf/2.38.1_1/include/gdk-pixbuf-2.0
		${BREW}/Cellar/glib/2.60.6/include
		${BREW}/Cellar/glib/2.60.6/include/glib-2.0
		${BREW}/Cellar/glib/2.60.6/lib/glib-2.0/include
		${BREW}/opt/gettext/include
		${BREW}/Cellar/pcre/8.43/include)

set(GTK_LINKS
		${BREW}/Cellar/gtk+3/3.24.10/lib
		${BREW}/Cellar/pango/1.44.5/lib
		${BREW}/Cellar/harfbuzz/2.5.3/lib
		${BREW}/Cellar/atk/2.32.0_1/lib
		${BREW}/Cellar/cairo/1.16.0_2/lib
		${BREW}/Cellar/gdk-pixbuf/2.38.1_1/lib
		${BREW}/Cellar/glib/2.60.6/lib
		${BREW}/opt/gettext/lib)

include_directories(
		${GTK_INCLUDES}
		#	${GTK3_INCLUDE_DIRS}
		../21_libft/includes/
		./parameters/
		./gui/
		./gui/gui/
		./gui/gui_camera/
		./gui/gui_object_x/
		./gui/gui_color/
		./gui/gui_material/
		./gui/gui_scene_edit/
		./gui/gui_scene_add/
		./gui/object_add/
		./gui/gui_scene/
		./gui/gui_settings/
		./gui/gui_image/
		./gui/gui_signal_x
		./gui/gui_signal_connect/
		./cl_renderer/cl_renderer/
		./cl_renderer/color/
		./cl_renderer/light/
		./cl_renderer/object/
		./cl_renderer/object_x/
		./cl_renderer/scene/
		./cl_renderer/f4/
		./cl_renderer/camera/
		./cl_renderer/ray/
		./cl_renderer/intersection/
		./cl_renderer/assert
		./cl_renderer/material)

set(GTK3_LIBRARY_DIRS
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

link_directories(
		${GTK_LINKS}
		${GTK3_LIBRARY_DIRS}
		../21_libft/)

add_definitions(${GTK3_CFLAGS_OTHER})

link_libraries(
		"ft"
		"-framework OpenCL"
		#	"OpenCL"
		#	"m"
		${GTK3_LIBRARY_DIRS})

set(SOURCE_MAIN ./main.c)

set(SOURCE_GUI_GUI
		./gui/gui/gui_new.c
		./gui/gui/gui_delete.c
		./gui/gui/gui_load.c
		./gui/gui/gui_loop.c)

set(SOURCE_GUI_CAMERA
		./gui/gui_camera/gui_camera_new.c
		./gui/gui_camera/gui_camera_delete.c
		./gui/gui_camera/gui_camera_show.c)

set(SOURCE_GUI_OBJECT_X
		./gui/gui_object_x/gui_object_sphere_x.c
		./gui/gui_object_x/gui_object_plane_x.c
		./gui/gui_object_x/gui_object_x.c cl_renderer/object_x/object_cone.c cl_renderer/object_x/object_cylinder.c)

set(SOURCE_GUI_COLOR
		./gui/gui_color/gui_color_to_f4.c
		./gui/gui_color/gui_color_from_f4.c)

set(SOURCE_GUI_MATERIAL
		./gui/gui_material/gui_material_set.c
		./gui/gui_material/gui_material_show.c
		./gui/gui_scene_edit/gui_scene_edit_set_material.c
		./gui/gui_material/gui_material_build.c
		./gui/gui_scene_add/gui_scene_add_set_material.c)

set(SOURCE_GUI_SCENE_EDIT
		./gui/gui_scene_edit/gui_scene_edit_new.c
		./gui/gui_scene_edit/gui_scene_edit_delete.c
		./gui/gui_scene_edit/gui_scene_edit_update.c
		./gui/gui_scene_edit/gui_scene_edit_gen_name.c
		./gui/gui_scene_edit/gui_scene_edit_set_sphere.c
		./gui/gui_scene_edit/gui_scene_edit_set_plane.c
		./gui/gui_scene_edit/gui_scene_edit_get_object.c
		./gui/gui_scene_edit/gui_scene_edit_show.c)

set(SOURCE_GUI_SCENE_ADD
		./gui/gui_scene_add/gui_scene_add_new.c
		./gui/gui_scene_add/gui_scene_add_delete.c
		./gui/gui_scene_add/gui_scene_add_set_sphere.c
		./gui/gui_scene_add/gui_scene_add_update.c
		./gui/gui_scene_add/gui_scene_add_show.c
		./gui/gui_scene_add/gui_scene_add_get_object.c
		./gui/gui_scene_add/gui_scene_add_set_plane.c
		./gui/gui_scene_add/gui_scene_add_gen_name.c
		./gui/gui_scene_add/gui_scene_add_build_object.c)

set(SOURCE_GUI_SCENE
		./gui/gui_scene/gui_scene_new.c
		./gui/gui_scene/gui_scene_delete.c)

set(SOURCE_GUI_SETTINGS
		./gui/gui_settings/gui_settings_new.c
		./gui/gui_settings/gui_settings_delete.c)

set(SOURCE_GUI_IMAGE
		./gui/gui_image/gui_image_new.c
		./gui/gui_image/gui_image_delete.c)

set(SOURCE_GUI_SIGNAL_X
		./gui/gui_signal_x/gui_signal_exit.c
		./gui/gui_signal_x/gui_signal_key.c
		./gui/gui_signal_x/gui_signal_scene_edit_select.c
		./gui/gui_signal_x/gui_signal_object_edit_sphere_x.c
		./gui/gui_signal_x/gui_signal_object_edit_plane_name.c
		./gui/gui_signal_x/gui_signal_object_edit_plane_position_x.c
		./gui/gui_signal_x/gui_signal_object_edit_plane_normal_x.c
		./gui/gui_signal_x/gui_signal_scene_add_response_x.c
		./gui/gui_signal_x/gui_signal_scene_edit_add.c
		./gui/gui_signal_x/gui_signal_scene_edit_remove.c
		./gui/gui_signal_x/gui_signal_scene_add_type_x.c
		./gui/gui_signal_x/gui_signal_camera_position_x.c
		./gui/gui_signal_x/gui_signal_camera_rotation_x.c
		./gui/gui_signal_x/gui_signal_scene_edit_remove_response_x.c
		./gui/gui_signal_x/gui_signal_image_click.c
		./gui/gui_signal_x/gui_signal_scene_edit_material_x.c
		./gui/gui_signal_x/gui_signal_camera_filter_x.c)

set(SOURCE_GUI_SIGNAL_CONNECT
		./gui/gui_signal_connect/gui_signal_connect_all.c
		./gui/gui_signal_connect/gui_signal_connect_scene_edit.c
		./gui/gui_signal_connect/gui_signal_connect_macro.h
		./gui/gui_signal_connect/gui_signal_connect_object_edit_sphere.c
		./gui/gui_signal_connect/gui_signal_connect_object_edit_plane.c
		./gui/gui_signal_connect/gui_signal_connect_scene_add.c
		./gui/gui_signal_connect/gui_signal_connect_camera.c
		./gui/gui_signal_connect/gui_signal_connect_image.c)

set(SOURCE_GUI
		${SOURCE_GUI_GUI}
		${SOURCE_GUI_CAMERA}
		${SOURCE_GUI_OBJECT_X}
		${SOURCE_GUI_COLOR}
		${SOURCE_GUI_MATERIAL}
		${SOURCE_GUI_SCENE_EDIT}
		${SOURCE_GUI_SCENE_ADD}
		${SOURCE_GUI_SCENE}
		${SOURCE_GUI_SETTINGS}
		${SOURCE_GUI_IMAGE}
		${SOURCE_GUI_SIGNAL_X}
		${SOURCE_GUI_SIGNAL_CONNECT})

set(SOURCE_CL_RENDERER_
		./cl_renderer/cl_renderer/cl_renderer_new.c
		./cl_renderer/cl_renderer/cl_renderer_delete.c
		./cl_renderer/cl_renderer/cl_renderer_init_device.c
		./cl_renderer/cl_renderer/cl_renderer_init_context.c
		./cl_renderer/cl_renderer/cl_renderer_create_program.c
		./cl_renderer/cl_renderer/cl_renderer_create_queue.c
		./cl_renderer/cl_renderer/cl_renderer_create_kernel.c
		./cl_renderer/cl_renderer/cl_renderer_init_data.c
		./cl_renderer/cl_renderer/cl_renderer_set_arguments.c
		./cl_renderer/cl_renderer/cl_renderer_render.c
		./cl_renderer/cl_renderer/cl_renderer_log.c
		./cl_renderer/cl_renderer/cl_renderer_update.c
		./cl_renderer/cl_renderer/cl_renderer_reset_samples.c
		./cl_renderer/cl_renderer/cl_renderer_camera_x.c)

set(SOURCE_SCENE
		./cl_renderer/scene/scene_new.c
		./cl_renderer/scene/scene_get_space.c
		./cl_renderer/scene/scene_delete.c
		./cl_renderer/scene/scene_remove_object.c)

set(SOURCE_OBJECT
		./cl_renderer/object/object_build.c
		./cl_renderer/object_x/object_sphere.c
		./cl_renderer/object_x/object_plane.c
		./cl_renderer/object/object_translate.c)

set(SOURCE_F4
		./cl_renderer/f4/f4_add.c
		./cl_renderer/f4/f4_sub.c
		./cl_renderer/f4/f4_mul.c
		./cl_renderer/f4/f4_rotate.c cl_renderer/f4/f4_normalize.c cl_renderer/f4/f4_length.c)

set(SOURCE_CAMERA
		./cl_renderer/camera/camera_new.c
		./cl_renderer/camera/camera_delete.c
		./cl_renderer/camera/camera_move.c
		./cl_renderer/camera/camera_rotate.c
		./cl_renderer/camera/camera_apply.c)

set(SOURCE_RAY
		./cl_renderer/ray/ray)

set(SOURCE_CL_RENDERER
		${SOURCE_CL_RENDERER_}
		${SOURCE_SCENE}
		${SOURCE_OBJECT}
		${SOURCE_F4}
		${SOURCE_CAMERA}
		${SOURCE_ASSERT})

add_executable(rt
		${SOURCE_MAIN}
		${SOURCE_GUI}
		${SOURCE_CL_RENDERER})