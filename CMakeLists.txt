cmake_minimum_required(VERSION 3.14)
project(rp_sdl C)

set(CMAKE_C_STANDARD 99)

link_directories(
        ./sdl2/2.0.9_1/lib
        ../21_libft/)

include_directories(
        ./sdl2/2.0.9_1/include/SDL2
        ../21_libft/includes
        ./
        ./sdl_ctrl/)

link_libraries(
        "SDL2"
        "ft")

add_executable(rp_sdl
        ./main.c
        ./sdl_ctrl/cdl_ctrl_new.c
        ./sdl_ctrl/sdl_ctrl_init.c
        ./sdl_ctrl/sdl_ctrl_delete.c
        ./sdl_ctrl/sdl_ctrl_error.c)

