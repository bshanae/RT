cmake_minimum_required(VERSION 3.14)
project(rt C)

set(CMAKE_CFLAGS "${CMAKE_CFALGS} -Wall -Wextra")

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(
	${GTK3_INCLUDE_DIRS}
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
	./renderer/
	./camera/
	./ray/
	./intersection/
	./ft_assert/
	./open_cl_manager/)

link_directories(
	${GTK3_LIBRARY_DIRS}
	../21_libft/)

add_definitions(
	${GTK3_CFLAGS_OTHER})

link_libraries(
	${GTK3_LIBRARIES}
	"m"
	"ft")

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

set(SOURCE_RENDERER
	./renderer/renderer_new.c
	./renderer/renderer_delete.c
	./renderer/renderer_pixel.c
	./renderer/renderer_frame.c)

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

set(SOURCE_FT_ASSERT ft_assert/ft_assert.c)

set(SOURCE_OPEN_CL_MANAGER
	./open_cl_manager/open_cl_manager_new.c
	./open_cl_manager/open_cl_manager_delete.c open_cl_manager/open_cl_manager_init_device.c open_cl_manager/open_cl_manager_init_context.c open_cl_manager/open_cl_manager_create_program.c)

set(SOURCE_RAY
	./ray/ray)

add_executable(rt
	${SOURCE_MAIN}
	${SOURCE_GUI}
	${SOURCE_VECTOR3}
	${SOURCE_RENDERER}
	${SOURCE_SCENE}
	${SOURCE_OBJECT}
	${SOURCE_CAMERA}
	${SOURCE_FT_ASSERT}
	${SOURCE_OPEN_CL_MANAGER})