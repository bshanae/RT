cmake_minimum_required(VERSION 3.14)
project(rp C)

set(CMAKE_C_STANDARD 99)

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra")

add_executable(rp
        ./main.c
        ./vector3/vector3.c
        ./rp/rp.c ray/ray.h
        ./camera/camera.c
        ./color/color.c
        ./rp/rp_hooks.c
        ./scene/scene.c
        ./ray/ray.c
        ./intersection/intersection.c
        ./shape/shape.c
        ./shape/shape_sphere.c
        ./shape/shape_plane.c
        ./shape/shape_cylinder.c
        ./shape/shape_aabb.c
        ./rp/rp_render.c)

target_include_directories(rp
        PRIVATE ../21_libft/includes
        PRIVATE ./
        PRIVATE ./vector3
        PRIVATE ./color
        PRIVATE ./ray
        PRIVATE ./light
        PRIVATE sphere
        PRIVATE ./material
        PRIVATE ./camera
        PRIVATE ./intersection
        PRIVATE ./rp
        PRIVATE ./sphere
        PRIVATE ./scene
        PRIVATE ./shape)

target_link_directories(rp
        PRIVATE /usr/local/lib
        PRIVATE /usr/X11/lib
        PRIVATE ../21_libft/)

target_link_libraries(rp
        "ft"
        "mlx"
        "-framework OpenGL"
        "-framework OpenCL"
        "-framework AppKit")
