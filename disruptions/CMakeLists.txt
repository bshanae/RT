cmake_minimum_required(VERSION 3.14)
project(disruptions C)

set(CMAKE_C_STANDARD 11)

link_directories(
        ~/.brew/lib
        ~/21_libft/)

include_directories(
        ~/.brew/include/SDL2
        ~/21_libft/includes
        ./)

link_libraries(
        "SDL2"
        "ft")

add_executable(disruptions
        sdl/sdl_my.h
        ./sdl/sdl_init.c
        preferences.h
        main.c
        ./sdl/sdl_new.c sdl/sdl_error.c sdl/sdl_delete.c sdl/sdl_upload.c sdl/sdl_put_image.c disruptions.h perlin_noise/perlin_noise_math.c perlin_noise/perlin_noise.h vector2/vector2.h vector2/vector2.c perlin_noise/perlin_noise_generator.c)