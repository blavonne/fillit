cmake_minimum_required(VERSION 3.14)
project(fillit C)

set(CMAKE_C_STANDARD 99)

add_executable(fillit
        main.c
        read.c
        fillit.h
        figures_code.c
        figures_list.c
        salvation.c
        solutions_list.c checks.c libft/ft_put_errmsg.c)

target_link_libraries(fillit
        LINK_PUBLIC ${CMAKE_SOURCE_DIR}/libft/libft.a)