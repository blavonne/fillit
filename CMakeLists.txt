cmake_minimum_required(VERSION 3.14)
project(fillit C)

set(CMAKE_C_STANDARD 99)

add_executable(fillit
        main.c
        read.c
        fillit.h
        figures_code.c
        t_figure.c
        prepare.c
        t_solution.c
        checks.c solution.c)

target_link_libraries(fillit
        LINK_PUBLIC ${CMAKE_SOURCE_DIR}/libft/libft.a)