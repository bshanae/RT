cmake_minimum_required(VERSION 3.14)
project(rp_sdl C)

set(CMAKE_C_STANDARD 99)

link_directories(
        ./sdl2/2.0.9_1/lib
        ../21_libft/)

find_package(SDL2 REQUIRED)

include_directories(
        ${SDL2_INCLUDE_DIRS}
        ../21_libft/includes
        ./
        ./sdl_ctrl/
        ./vector3/
        ./camera
        ./filter
        ./shape
        ./light
        ./scene
        ./color
        ./material
        ./intersection
        ./renderer/)

link_libraries(
        ${SDL2_LIBRARIES}
        "ft")

add_executable(rp_sdl
        ./main.c
        ./sdl_ctrl/cdl_ctrl_new.c
        ./sdl_ctrl/sdl_ctrl_init.c
        ./sdl_ctrl/sdl_ctrl_delete.c
        ./sdl_ctrl/sdl_ctrl_error.c
        ./renderer/renderer_new.c
        ./renderer/renderer_delete.c
        ./renderer/renderer_update_frame.c
        ./renderer/renderer_loop.c
        ./renderer/renderer_radiance.c
        ./renderer/renderer_write_radience.c
        ./camera/camera_new.c
        ./camera/camera_delete.c
        ./camera/camera_build_ray.c
        ./vector3/vector3_mul.c
        ./vector3/vector3_add.c
        ./vector3/vector3_sub.c
        ./vector3/vector3_dot.c
        ./vector3/vector3_length.c
        ./vector3/vector3_normal.c
        ./vector3/vector3_cross.c
        ./renderer/renderer_build_ray.c
        ./filter/filter_jitter_sample.c
        ./sdl_ctrl/sdl_ctrl_upload.c
        ./shape/shape.c
        ./shape/shape_sphere.c
        ./shape/shape_plane.c
        ./intersection/intersection_calculate.c
        ./scene/scene.c
        ./color/color_unpack.c)

