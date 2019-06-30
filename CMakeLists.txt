cmake_minimum_required(VERSION 3.14)
project(rt C)

set(CMAKE_C_STANDARD 99)

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra")

add_executable(rt
        ./main.c
        ./vector3/vector3.c
        ./camera/camera.c
        ./rt/rt.c
        ./scene/scene.c
        ./shape/shape_sphere.c
        ./rt/rt_mlx.c
        ./light/light.c
        ./shape/shape_plane.c
        ./shape/shape_cylinder.c
        ./shape/shape.c
        ./shape/shape_aabb.c
        ./shape/shape_cone.c
        ./open_cl/open_cl.c scene/scene_a.c material/material_list.h color/color_list.h scene/scene_list.h open_cl/open_cl_error.c open_cl/open_cl_create_program.c open_cl/open_cl_create_context.c open_cl/open_cl_create_device.c open_cl/open_cl_create_queue.c open_cl/open_cl_create_kernel.c open_cl/open_cl_alloc_device_data.c open_cl/open_cl_set_arguments.c rt/rt_clone.c rt/rt_control.c)

target_include_directories(rt
        PRIVATE /usr/local/include
        PRIVATE /usr/X11/include
        PRIVATE ../21_libft/includes
        PRIVATE vector3
        PRIVATE camera
        PRIVATE rt
        PRIVATE ray
        PRIVATE intersection
        PRIVATE scene
        PRIVATE color
        PRIVATE shape
        PRIVATE material
        PRIVATE light
        PRIVATE mlx
        PRIVATE open_cl
        PRIVATE float_macro
        PRIVATE ./)

target_link_directories(rt
        PRIVATE /usr/local/lib
        PRIVATE /usr/X11/lib
        PRIVATE ../21_libft/)

target_link_libraries(rt
        "ft"
        "mlx"
        "-framework OpenGL"
        "-framework OpenCL"
        "-framework AppKit")
