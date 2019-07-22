cmake_minimum_required(VERSION 3.14)
project(pt_sdl C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3")

link_directories(
        ~/.brew/Cellar/sdl2/2.0.9_1/lib
        /usr/local/Cellar/sdl2/2.0.9_1/lib
        ../21_libft/)

include_directories(
        ~/.brew/Cellar/sdl2/2.0.9_1/include/SDL2
        /usr/local/Cellar/sdl2/2.0.9_1/include/SDL2
        ../21_libft/includes
        ./
        ./sdl_ctrl/
        ./vector3/
        ./camera
        ./filter
        ./shape
        ./mesh
        ./kd_tree
        ./light
        ./scene
        ./color
        ./material
        ./ray
        ./intersection
        ./renderer/
        ./sampler
        ./obj_parser)

link_libraries(
       "SDL2"
        "ft")

set(SOURCE_VECTOR
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

set(SOURCE_SDL_CTRL
        ./sdl_ctrl/cdl_ctrl_new.c
        ./sdl_ctrl/sdl_ctrl_delete.c
        ./sdl_ctrl/sdl_ctrl_error.c
        ./sdl_ctrl/sdl_ctrl_init.c
        ./sdl_ctrl/sdl_ctrl_upload.c)

set(SOURCE_RAY
        ./ray/ray_calculate.c)

set(SOURCE_CAMERA
        ./camera/camera_new.c
        ./camera/camera_delete.c
        ./camera/camera_build_ray.c
        ./camera/camera_focus.c)

set(SOURCE_FILTER
        ./filter/filter_jitter_sample.c)

set(SOURCE_RENDERER
        ./renderer/renderer_new.c
        ./renderer/renderer_delete.c
        ./renderer/renderer_loop.c
        ./renderer/renderer_update_frame.c
        ./renderer/renderer_build_ray.c
        ./renderer/renderer_radiance.c
        ./renderer/renderer_radiance_light.c
        ./renderer/renderer_write_radience.c
        ./renderer/renderer_check_interval.c)

set(SOURCE_COLOR
        ./color/color_unpack.c
        ./color/color_correct.c)

set(SOURCE_SCENE
        ./scene/scene.c)

set(SOURCE_SHAPE
        ./shape/shape.c
        ./shape/shape_sphere.c
        ./shape/shape_plane.c
        ./shape/shape_triangle.c)

set(SOURCE_MESH
        ./mesh/mesh_new.c
        ./mesh/mesh_delete.c
        ./mesh/mesh_intersect.c)

set(SOURCE_KD_TREE
        ./kd_tree/kd_tree_build.c kd_tree/kd_tree_array_create.c kd_tree/kd_tree_bb_create.c)

set(SOURCE_OBJ_PARSER
        ./obj_parser/open_file.c)

set(SOURCE_INTERSECTION
        ./intersection/intersection_reflect.c
        ./intersection/intersection_refract.c)

set(SOURCE_SAMPLER
        ./sampler/sampler_transform.c
        ./sampler/sampler_uniform.c
        ./sampler/sampler_cosine.c)

set(SOURCE_MAIN
        ./main.c
#        ./obj_parser/test.c
        kd_tree/kd_tree_node_create.c)

add_executable(pt_sdl
        ${SOURCE_VECTOR}
        ${SOURCE_SDL_CTRL}
        ${SOURCE_RAY}
        ${SOURCE_CAMERA}
        ${SOURCE_FILTER}
        ${SOURCE_RENDERER}
        ${SOURCE_COLOR}
        ${SOURCE_SCENE}
        ${SOURCE_SHAPE}
        ${SOURCE_MESH}
        ${SOURCE_KD_TREE}
        ${SOURCE_OBJ_PARSER}
        ${SOURCE_INTERSECTION}
        ${SOURCE_SAMPLER}
        ${SOURCE_MAIN})

