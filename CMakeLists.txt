cmake_minimum_required(VERSION 3.14)
project(test_gui C)

set(CMAKE_CFLAGS "${CMAKE_CFALGS} -Wall -Wextra")

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(
	${GTK3_INCLUDE_DIRS}
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
	./renderer)

link_directories(
	${GTK3_LIBRARY_DIRS})

add_definitions(
	${GTK3_CFLAGS_OTHER})

link_libraries(
	${GTK3_LIBRARIES})

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

set(SOURCE_RENDERER
	./renderer/renderer_new.c)

set(SOURCE_SCENE
	./scene/scene_new.c
	./scene/scene_get_space.c)

set(SOURCE_OBJECT
	./object/object_build.c
	./object_list/sphere.c
	./object/object_intersect.c
	./object_list/plane.c gui/gui_signal/gui_s_key.c)

add_executable(test_gui
	${SOURCE_MAIN}
	${SOURCE_GUI}
	${SOURCE_RENDERER}
	${SOURCE_SCENE}
	${SOURCE_OBJECT})