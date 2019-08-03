cmake_minimum_required(VERSION 3.14)
project(test_gui C)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(
	${GTK3_INCLUDE_DIRS}
	./gui/
	./gui/gui
	./gui/gui_scene
	./gui/gui_scene_params
	./gui/gui_scene_list)

link_directories(
	${GTK3_LIBRARY_DIRS})

add_definitions(
	${GTK3_CFLAGS_OTHER})

link_libraries(
	${GTK3_LIBRARIES})

add_executable(test_gui
	./main.c
	./gui/gui/gui_new.c
	./gui/gui/gui_init.c
	./gui/gui/gui_start.c
	./gui/gui_scene/gui_scene_new.c
	./gui/gui_scene_list/gui_scene_list_new.c
	./gui/gui_scene_list/gui_scene_list_init.c
	./gui/gui_scene_params/gui_scene_params_new.c
	./gui/gui_scene_params/gui_scene_params_init.c
	./gui/gui_scene_params/gui_scene_param_init.c
	./gui/gui_scene/gui_scene_init.c)