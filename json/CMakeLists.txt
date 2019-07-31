cmake_minimum_required(VERSION 3.14)
project(json_tester C)

set(CMAKE_C_STANDARD 11)

link_directories(
        ~/.brew/Cellar/json-c/0.13.1/lib
        ~/21_libft/)

include_directories(
        ~/.brew/Cellar/json-c/0.13.1/include/json-c
)

link_libraries(
        "json-c"
"ft")

add_executable(json_tester
        test.c)
