cmake_minimum_required(VERSION 3.14)
project(rt C)

set(RT_GTK_PKG ON)
set(RT_LINUX ON)

if (${RT_GTK_PKG})
	find_package(PkgConfig REQUIRED)
	pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
endif()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wenum-compare -Wno-deprecated-declarations")

if (${RT_LINUX})
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D RT_OPEN_CL_DISABLED -D RT_QUEUE_MANUAL")
endif ()

set(BREW ~/.brew)

set(RT_GTK_INCLUDES
	${BREW}/Cellar/libffi/3.2.1/lib/libffi-3.2.1/include
	${BREW}/Cellar/gtk+3/3.24.11/include/gtk-3.0
	${BREW}/Cellar/glib/2.62.0/include/gio-unix-2.0
	${BREW}/Cellar/cairo/1.16.0_2/include/cairo
	${BREW}/Cellar/libepoxy/1.5.3/include
	${BREW}/Cellar/pango/1.44.6/include/pango-1.0
	${BREW}/Cellar/fribidi/1.0.5/include/fribidi
	${BREW}/Cellar/harfbuzz/2.6.1/include/harfbuzz
	${BREW}/Cellar/graphite2/1.3.13/include
	${BREW}/Cellar/atk/2.34.1/include/atk-1.0
	${BREW}/Cellar/cairo/1.16.0_2/include/cairo
	${BREW}/Cellar/pixman/0.38.4/include/pixman-1
	${BREW}/Cellar/fontconfig/2.13.1/include -I/Users/ashari/.brew/opt/freetype/include/freetype2
	${BREW}/Cellar/libpng/1.6.37/include/libpng16
	${BREW}/Cellar/gdk-pixbuf/2.38.2/include/gdk-pixbuf-2.0
	${BREW}/Cellar/glib/2.62.0/include
	${BREW}/Cellar/glib/2.62.0/include/glib-2.0
	${BREW}/Cellar/glib/2.62.0/lib/glib-2.0/include -I/Users/ashari/.brew/opt/gettext/include
	${BREW}/Cellar/pcre/8.43/include)

set(RT_GTK_LIBRARY_DIRS
	${BREW}/Cellar/gtk+3/3.24.11/lib
	${BREW}/Cellar/pango/1.44.6/lib
	${BREW}/Cellar/harfbuzz/2.6.1/lib
	${BREW}/Cellar/atk/2.34.1/lib
	${BREW}/Cellar/cairo/1.16.0_2/lib
	${BREW}/Cellar/gdk-pixbuf/2.38.2/lib
	${BREW}/Cellar/glib/2.62.0/lib)

set(RT_GTK_LIBRARIES
	"-L/Users/ashari/.brew/opt/gettext/lib"
	"-lgtk-3"
	"-lgdk-3"
	"-framework Cocoa"
	"-framework Carbon"
	"-framework CoreGraphics"
	"-lpangocairo-1.0"
	"-lpango-1.0"
	"-lharfbuzz"
	"-latk-1.0"
	"-lcairo-gobject"
	"-lcairo"
	"-lgdk_pixbuf-2.0"
	"-lgio-2.0"
	"-lgobject-2.0"
	"-lglib-2.0"
	"-lintl")

if (${RT_GTK_PKG})
	include_directories(${GTK3_INCLUDE_DIRS})
else ()
	include_directories(${RT_GTK_INCLUDES})
endif ()

include_directories(
	../21_libft/includes/
	./error_framework/
	./parameters/
	./gui/gui/
	./gui/gui_queue/
	./gui/gui_entry/
	./gui/gui_control/
	./gui/gui_icon/
	./gui/gui_parser/
	./gui/gui_camera/
	./gui/gui_object_x/
	./gui/gui_color/
	./gui/gui_material/
	./gui/gui_scene_common/
	./gui/gui_scene_background/
	./gui/gui_scene_edit/
	./gui/gui_scene_add/
	./gui/object_add/
	./gui/gui_scene/
	./gui/gui_settings/
	./gui/gui_image/
	./gui/gui_signal_x
	./gui/gui_signal_connect_x/
	./cl_renderer/color/
	./cl_renderer/light/
	./cl_renderer/object/
	./cl_renderer/object_x/
	./cl_renderer/scene/
	./cl_renderer/f4/
	./cl_renderer/f2/
	./cl_renderer/camera/
	./cl_renderer/ray/
	./cl_renderer/intersection/
	./cl_renderer/material
	./cl_renderer/cl_program/
	./cl_renderer/cl_arg_list/
	./cl_renderer/cl_builder/
	./cl_renderer/rt_settings/
	./cl_renderer/cl_renderer/
	./cl_renderer/json/
	./cl_renderer/texture
	./cl_renderer/disruption_x)

if (${RT_GTK_PKG})
	link_directories(${GTK3_LIBRARY_DIRS})
else ()
	link_directories(${RT_GTK_LIBRARY_DIRS})
endif ()

link_directories(../21_libft/)

if (${RT_GTK_PKG})
	add_definitions(${GTK3_CFLAGS_OTHER})
endif ()

if (${RT_LINUX})
	link_libraries(
		"OpenCL"
		"m"
		"bsd" )
else()
	link_libraries("-framework OpenCL")
endif()

if (${RT_GTK_PKG})
	link_libraries(${GTK3_LIBRARIES})
else ()
	link_libraries(${RT_GTK_LIBRARIES})
endif ()

link_libraries("ft")

set(SOURCE_ERROR_FRAMEWORK
	./error_framework/rt_raise_x.c
	./error_framework/rt_assert_x.c
	./error_framework/rt_malloc.c error_framework/rt_print_error.c)

set(SOURCE_MAIN
	./main.c)

set(SOURCE_GUI_GUI
	./gui/gui/gui_new.c
	./gui/gui/gui_delete.c
	./gui/gui/gui_update.c
	./gui/gui/gui_loop.c
	./gui/gui/gui_render.c
	./gui/gui/gui_resize_x.c "gui/gui/gui_commnad_x.c" gui/gui/gui_connect.c)

set(SOURCE_GUI_QUEUE
	./gui/gui_queue/gui_queue_new.c
	./gui/gui_queue/gui_queue_delete.c
	./gui/gui_queue/gui_queue_push.c
	./gui/gui_queue/gui_queue_execute_x.c
	./gui/gui_queue/gui_queue_start.c
	"./gui/gui_queue/gui_queue_(un)block.c"
	./gui/gui_queue/gui_queue_wait.c
	./gui/gui_queue/gui_queue_get_time.c)

set(SOURCE_GUI_ENTRY
	./gui/gui_entry/gui_entry_set_x.c
	./gui/gui_entry/gui_entry_get_x.c)

set(SOURCE_GUI_CONTROL
	gui/gui_control/gui_control_x.c)

set(SOURCE_GUI_ICON
	./gui/gui_icon/gui_icon_load.c
	./gui/gui_icon/gui_icon_load_all.c)

set(SOURCE_GUI_PARSER
	./gui/gui_parser/gui_parser_new.c
	./gui/gui_parser/gui_parser_delete.c
	./gui/gui_parser/gui_parser_update.c
	./gui/gui_signal_connect_x/gui_signal_connect_parser.c
	./gui/gui_queue/gui_finish.c)

set(SOURCE_GUI_CAMERA
	./gui/gui_camera/gui_camera_new.c
	./gui/gui_camera/gui_camera_delete.c
	./gui/gui_camera/gui_camera_show.c
	./gui/gui_camera/gui_camera_apply.c
	gui/gui_signal_x/gui_signal_camera_state_x.c gui/gui_camera/gui_camera_connect.c)

set(SOURCE_GUI_OBJECT_X
	./gui/gui_object_x/gui_object_light_point_x.c
	./gui/gui_object_x/gui_object_light_direct_x.c
	./gui/gui_object_x/gui_object_sphere_x.c
	./gui/gui_object_x/gui_object_plane_x.c
	./gui/gui_object_x/gui_object_cone_x.c
	./gui/gui_object_x/gui_object_cylinder_x.c
	./gui/gui_object_x/gui_object_box_x.c
	./gui/gui_object_x/gui_object_paraboloid_x.c
	./gui/gui_object_x/gui_object_moebius_x.c
	./gui/gui_object_x/gui_object_torus_x.c
	./gui/gui_object_x/gui_object_mandelbulb_x.c
	./gui/gui_object_x/gui_object_julia_x.c
	./gui/gui_object_x/gui_object_p_cube_x.c
	./gui/gui_object_x/gui_object_explosion_x.c
	./gui/gui_object_x/gui_object_pair_x.c)

set(SOURCE_GUI_COLOR
	./gui/gui_color/gui_color_to_f4.c
	./gui/gui_color/gui_color_from_f4.c)

set(SOURCE_GUI_MATERIAL
	./gui/gui_material/gui_material_init.c
	./gui/gui_material/gui_material_get.c
	./gui/gui_material/gui_material_set.c
	./gui/gui_material/gui_material_color_x.c
	./gui/gui_material/gui_material_switch_mod.c
	./gui/gui_material/gui_material_texture_x.c
	./gui/gui_material/gui_material_special_x.c
	./gui/gui_material/gui_material_prepare.c gui/gui_material/gui_material_hide.c)

set(SOURCE_GUI_SCENE_COMMON
	./gui/gui_scene_common/gui_scene_common_new.c
	./gui/gui_scene_common/gui_scene_common_delete.c
	./gui/gui_scene_common/gui_scene_common_gen_name.c
	./gui/gui_scene_common/gui_scene_common_update_x.c
	./gui/gui_scene_common/gui_scene_common_add_to_list.c gui/gui_scene_common/gui_scene_common_connect.c)

set(SOURCE_GUI_SCENE_EDIT
	./gui/gui_scene_edit/gui_scene_edit_new.c
	./gui/gui_scene_edit/gui_scene_edit_delete.c
	./gui/gui_scene_edit/gui_scene_edit_show.c
	./gui/gui_scene_edit/gui_scene_edit_init_sphere.c
	./gui/gui_scene_edit/gui_scene_edit_init_plane.c
	./gui/gui_scene_edit/gui_scene_edit_init_cone.c
	./gui/gui_scene_edit/gui_scene_edit_init_cylinder.c
	./gui/gui_scene_edit/gui_scene_edit_init_material.c
	./gui/gui_scene_edit/gui_scene_edit_apply.c
	./gui/gui_scene_edit/gui_scene_edit_init_light_x.c
	./gui/gui_scene_edit/gui_scene_edit_init_box.c
	./gui/gui_scene_edit/gui_scene_edit_init_paraboloid.c
	./gui/gui_scene_edit/gui_scene_edit_init_moebius.c
	./gui/gui_scene_edit/gui_scene_edit_init_torus.c
	./gui/gui_scene_edit/gui_scene_edit_init_mandelbulb.c
	./gui/gui_scene_edit/gui_scene_edit_init_julia.c
	./gui/gui_scene_edit/gui_scene_edit_init_own.c
	./gui/gui_scene_edit/gui_scene_edit_init_p_cube.c
	./gui/gui_scene_edit/gui_scene_edit_init_limited.c
	./gui/gui_scene_edit/gui_scene_edit_init_explosion.c
	./gui/gui_scene_edit/gui_scene_edit_init_csg.c
	"gui/gui_scene_edit/gui_scene_edit_(un)select.c" gui/gui_scene_edit/gui_scene_edit_background_x.c)

set(SOURCE_GUI_SCENE_ADD
	./gui/gui_scene_add/gui_scene_add_new.c
	./gui/gui_scene_add/gui_scene_add_delete.c
	./gui/gui_scene_add/gui_scene_add_init_sphere.c
	./gui/gui_scene_add/gui_scene_add_init_plane.c
	./gui/gui_scene_add/gui_scene_add_gen_name.c
	./gui/gui_scene_add/gui_scene_add_build_object.c
	./gui/gui_scene_add/gui_scene_add_init_cone.c
	./gui/gui_scene_add/gui_scene_add_init_cylinder.c
	./gui/gui_scene_add/gui_scene_add_init_material.c
	./gui/gui_scene_add/gui_scene_add_init_light_x.c
	./gui/gui_scene_add/gui_scene_add_init_box.c
	./gui/gui_scene_add/gui_scene_add_init_paraboloid.c
	./gui/gui_scene_add/gui_scene_add_init_moebius.c
	./gui/gui_scene_add/gui_scene_add_init_torus.c
	./gui/gui_scene_add/gui_scene_add_init_mandelbulb.c
	./gui/gui_scene_add/gui_scene_add_init_julia.c
	./gui/gui_scene_add/gui_scene_add_init_own.c
	./gui/gui_scene_add/gui_scene_add_init_limited.c
	./gui/gui_scene_add/gui_scene_add_init_p_cube.c
	./gui/gui_scene_add/gui_scene_add_init_explosion.c
	./gui/gui_scene_add/gui_scene_add_prepare.c)

set(SOURCE_GUI_SCENE
	./gui/gui_scene/gui_scene_new.c
	./gui/gui_scene/gui_scene_delete.c)

set(SOURCE_GUI_SETTINGS
	./gui/gui_settings/gui_settings_new.c
	./gui/gui_settings/gui_settings_delete.c
	./gui/gui_settings/gui_settings_reset.c
	./gui/gui_settings/gui_settings_apply.c
	./gui/gui_settings/gui_settings_show.c gui/gui_settings/gui_settings_connect.c)

set(SOURCE_GUI_IMAGE
	./gui/gui_image/gui_image_new.c
	./gui/gui_image/gui_image_delete.c
	./gui/gui_image/gui_image_allocate.c)

set(SOURCE_GUI_SIGNAL_X
	./gui/gui_signal_x/gui_signal_exit.c
	./gui/gui_signal_x/gui_signal_key.c
	./gui/gui_signal_x/gui_signal_scene_edit_select.c
	./gui/gui_signal_x/gui_signal_scene_add_response_x.c
	./gui/gui_signal_x/gui_signal_scene_edit_add.c
	./gui/gui_signal_x/gui_signal_scene_edit_remove.c
	gui/gui_signal_x/gui_signal_scene_add_type_select.c
	./gui/gui_signal_x/gui_signal_scene_edit_remove_response_x.c
	./gui/gui_signal_x/gui_signal_image_x.c
	./gui/gui_signal_x/gui_signal_scene_edit_reset.c
	./gui/gui_signal_x/gui_signal_scene_edit_apply.c
	./gui/gui_signal_x/gui_signal_scene_edit_material_x.c
	./gui/gui_signal_x/gui_signal_camera_apply.c
	./gui/gui_signal_x/gui_signal_camera_reset.c
	./gui/gui_signal_x/gui_signal_camera_filter_x.c
	./gui/gui_signal_x/gui_signal_settings_resize.c
	./gui/gui_signal_x/gui_signal_settings_light.c
	./gui/gui_signal_x/gui_signal_settings_tracing_x.c
	./gui/gui_signal_x/gui_signal_settings_reset.c
	./gui/gui_signal_x/gui_signal_settings_apply.c
	./gui/gui_signal_x/gui_signal_scene_add_material_x.c
	./gui/gui_signal_x/gui_signal_camera_screen_x.c
	./gui/gui_signal_x/gui_signal_parser_select.c
	./gui/gui_signal_x/gui_signal_parser_load.c
	./gui/gui_signal_x/gui_signal_camera_antialiasing.c
	./gui/gui_signal_x/gui_signal_camera_focus_x.c
	./gui/gui_signal_x/gui_signal_scene_edit_combo_changed.c
	./gui/gui_signal_x/gui_signal_entry_x.c
	./gui/gui_signal_x/gui_signal_scene_add_block_destroy.c
	./gui/gui_scene_add/gui_scene_add_init_csg.c
	./gui/gui_signal_x/gui_signal_scene_edit_switch_x.c
	./gui/gui_signal_x/gui_signal_settings_illumination_state.c
	./gui/gui_signal_x/gui_signal_scene_edit_scale_changed.c
	./gui/gui_signal_x/gui_signal_scene_add_switch_x.c
	./gui/gui_signal_x/gui_signal_settings_motion_blur.c)

set(SOURCE_GUI_SIGNAL_CONNECT_X
	./gui/gui_signal_connect_x/gui_signal_connect_all.c
	./gui/gui_signal_connect_x/gui_signal_connect_scene_edit.c
	./gui/gui_signal_connect_x/gui_signal_connect_scene_add.c
	./gui/gui_signal_connect_x/gui_signal_connect_camera.c
	./gui/gui_signal_connect_x/gui_signal_connect_image.c
	./gui/gui_signal_connect_x/gui_signal_connect_settings.c
	gui/gui_signal_connect_x/gui_signal_connect_entry.c)

set(SOURCE_GUI
	${SOURCE_GUI_GUI}
	${SOURCE_GUI_QUEUE}
	${SOURCE_GUI_CONTROL}
	${SOURCE_GUI_ENTRY}
	${SOURCE_GUI_ICON}
	${SOURCE_GUI_PARSER}
	${SOURCE_GUI_CAMERA}
	${SOURCE_GUI_OBJECT_X}
	${SOURCE_GUI_COLOR}
	${SOURCE_GUI_MATERIAL}
	${SOURCE_GUI_SCENE_COMMON}
	${SOURCE_GUI_SCENE_EDIT}
	${SOURCE_GUI_SCENE_ADD}
	${SOURCE_GUI_SCENE}
	${SOURCE_GUI_SETTINGS}
	${SOURCE_GUI_IMAGE}
	${SOURCE_GUI_SIGNAL_X}
	${SOURCE_GUI_SIGNAL_CONNECT_X})

set(SOURCE_JSON
	./cl_renderer/json/json_helper.c
	./cl_renderer/json/json_worker.c
	./cl_renderer/json/json_objects.c
	./cl_renderer/json/readfile.c)

set(SOURCE_TEXTURE
	./cl_renderer/texture/texture_initialization.c
	./cl_renderer/texture/texture_convert.c
	./cl_renderer/texture/texture_data_load.c
	./cl_renderer/texture/texture_disruptions_load.c
	./cl_renderer/texture/texture_fill_data.c
	./cl_renderer/texture/texture_iter.c
	)

set(SOURCE_DISRUPTION_X
	./cl_renderer/disruption_x/disruption_checkerboard.c
	./cl_renderer/disruption_x/disruption_sine_wave.c
	./cl_renderer/disruption_x/disruption_perlin_noise.c
	./cl_renderer/disruption_x/disruption_math.c)

set(SOURCE_F2
	./cl_renderer/f2/f2_add.c
	./cl_renderer/f2/f2_mul.c
	./cl_renderer/f2/f2_sub.c
	./cl_renderer/f2/f2_dot.c)

set(SOURCE_F4
	./cl_renderer/f4/f4_add.c
	./cl_renderer/f4/f4_sub.c
	./cl_renderer/f4/f4_mul.c
	cl_renderer/f4/f4_rotate_x.c
	./cl_renderer/f4/f4_length.c
	./cl_renderer/f4/f4_normalize.c
	./cl_renderer/f4/f4_dot.c)

set(SOURCE_OBJECT
	./cl_renderer/object/object_build.c
	./cl_renderer/object/object_translate.c
	./cl_renderer/object/object_flag_get.c)

set(SOURCE_OBJECT_X
	./cl_renderer/object_x/object_sphere.c
	./cl_renderer/object_x/object_plane.c
	./cl_renderer/object_x/object_cone.c
	./cl_renderer/object_x/object_cylinder.c
	./cl_renderer/object_x/object_box.c
	./cl_renderer/object_x/object_paraboloid.c
	./cl_renderer/object_x/object_moebius.c
	./cl_renderer/object_x/object_torus.c
	./cl_renderer/object_x/object_julia.c
	./cl_renderer/object_x/object_light_x.c
	./cl_renderer/object_x/object_mandelbulb.c
	./cl_renderer/object_x/object_limited.c
	./cl_renderer/object_x/object_perforated_cube.c
	./cl_renderer/object_x/object_explosion.c
	./cl_renderer/object_x/object_csg.c)

set(SOURCE_SCENE
	./cl_renderer/scene/scene_new.c
	./cl_renderer/scene/scene_get_space.c
	./cl_renderer/scene/scene_delete.c
	cl_renderer/scene/scene_object_x.c
	./cl_renderer/scene/scene_update.c
	./cl_renderer/scene/scene_clear.c
	./cl_renderer/scene/camera_point_check.c
	"cl_renderer/scene/scene_(un)select.c"
	./cl_renderer/scene/scene_edit_param.c
	./cl_renderer/scene/scene_set_x.c
	./cl_renderer/scene/scene_find_x_by_x.c
	./cl_renderer/scene/scene_func_x.c cl_renderer/scene/rt_background_translate.c)

set(SOURCE_RAY
	./cl_renderer/ray/ray)

set(SOURCE_CAMERA
	./cl_renderer/camera/camera_new.c
	./cl_renderer/camera/camera_delete.c
	./cl_renderer/camera/camera_move.c
	./cl_renderer/camera/camera_rotate.c
	./cl_renderer/camera/camera_apply.c
	./cl_renderer/camera/camera_request_x.c
	./cl_renderer/camera/camera_get_step.c)

set(SOURCE_CL_PROGRAM
	./cl_renderer/cl_program/cl_program_new.c
	./cl_renderer/cl_program/cl_program_delete.c
	./cl_renderer/cl_program/cl_program_concat.c
	./cl_renderer/cl_program/cl_program_build.c)

set(SOURCE_CL_ARG_LIST
	./cl_renderer/cl_arg_list/cl_arg_list_new.c
	./cl_renderer/cl_arg_list/cl_arg_list_delete.c
	./cl_renderer/cl_arg_list/cl_arg_list_push.c
	./cl_renderer/cl_arg_list/cl_arg_list_update.c
	./cl_renderer/cl_arg_list/cl_arg_list_read.c
	./cl_renderer/cl_arg_list/cl_arg_list_write.c)

set(SOURCE_CL_BUILDER
	./cl_renderer/cl_builder/cl_builder_new.c
	./cl_renderer/cl_builder/cl_builder_delete.c
	./cl_renderer/cl_builder/cl_builder_init_device.c
	./cl_renderer/cl_builder/cl_builder_create_x.c
	./cl_renderer/cl_builder/cl_builder_log.c
	./cl_renderer/cl_builder/cl_builder_set_args.c)

set(SOURCE_CL_RT_SETTINGS
	cl_renderer/rt_settings/rt_settings_init.c)

set(SOURCE_CL_RENDERER_
	./cl_renderer/cl_renderer/cl_renderer_new.c
	./cl_renderer/cl_renderer/cl_renderer_delete.c
	./cl_renderer/cl_renderer/cl_renderer_render.c
	./cl_renderer/cl_renderer/cl_renderer_camera_x.c
	./cl_renderer/cl_renderer/cl_renderer_flag_x.c
	cl_renderer/rt_settings/rt_settings_init.c
	./cl_renderer/cl_renderer/cl_renderer_load.c
	./cl_renderer/cl_renderer/cl_renderer_camera_request_x.c
	./cl_renderer/cl_renderer/cl_renderer_object_move.c
	cl_renderer/cl_renderer/cl_renderer_change_x.c)

set(SOURCE_RENDERER
	${SOURCE_F2}
	${SOURCE_F4}
	${SOURCE_JSON}
	${SOURCE_TEXTURE}
	${SOURCE_DISRUPTION_X}
	${SOURCE_OBJECT}
	${SOURCE_OBJECT_X}
	${SOURCE_SCENE}
	${SOURCE_CAMERA}
	${SOURCE_CL_PROGRAM}
	${SOURCE_CL_ARG_LIST}
	${SOURCE_CL_BUILDER}
	${SOURCE_CL_RT_SETTINGS}
	${SOURCE_CL_RENDERER_})

add_executable(rt
	${SOURCE_ERROR_FRAMEWORK}
	${SOURCE_MAIN}
	${SOURCE_GUI}
	${SOURCE_RENDERER})