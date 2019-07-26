cmake_minimum_required(VERSION 3.14)
project(test_gui C)

set(CMAKE_C_STANDARD 99)

include_directories(
        ./nuklear/
        ./sdl2/2.0.9_1/include/)

link_directories(
        ./sdl2/2.0.9_1/lib)

link_libraries(
        "sdl2"
)

add_executable(test_gui
        main.c)