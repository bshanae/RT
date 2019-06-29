cmake_minimum_required(VERSION 3.14)
project(rt C)

set(CMAKE_C_STANDARD 99)

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra")

add_executable(rt
        ./main.c
        ./vector3/vector3.c
        ./camera/camera.c
        ./rt/rt.c
        ./ray/ray.c
        ./scene/scene.c
        ./shape/shape_sphere.c
        ./scene/scene_shapes.c
        ./scene/scene_lights.c
        ./rt/rt_mlx.c
        ./light/light.c
        ./color/color.c
        ./material/material.c
        ./intersection/intersection.c
        ./shape/shape_plane.c
        ./shape/shape_cylinder.c
        ./shape/shape.c
        ./shape/shape_aabb.c
        ./console/console.c
        ./console/console_translate.c
        ./console/console_reflect.c
        ./shape/shape_cone.c
        ./shape/shape_disk.c
        ./console/console_diffuse.c
        ./console/console_specular.c
        ./console/console_shadows.c
        ./console/console_refract.c
        ./console/console_reset.c
        ./console/cosnole_tshadows.c
        ./rt/rt_consistent.c
        ./rt/rt_parallel.c
        ./console/console_parallel.c
        ./open_cl/open_cl.c
        ./test.c)

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
        PRIVATE console
        PRIVATE mlx
        PRIVATE open_cl
        PRIVATE float_macro)

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
