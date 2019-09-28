cmake_minimum_required(VERSION 3.14)
project(fillit C)

set(CMAKE_C_STANDARD 99)

add_executable(fillit
        fillit/main.c
        fillit/read.c
        fillit/fillit.h
        fillit//get_next_line.h
        fillit/get_next_line.c
        libft/libft.h
        libft/ft_bzero.c
        libft/ft_memchr.c
        libft/ft_strdup.c
        libft/ft_strjoin.c
        libft/ft_strlen.c
        libft/ft_strsub.c
        libft/ft_memset.c
        libft/ft_strcat.c
        libft/ft_strncpy.c
        libft/ft_strnew.c
        libft/ft_lstadd.c
        libft/ft_lstnew.c
        libft/ft_strchr.c
        libft/ft_memcpy.c
        libft/ft_lstdelone.c
        libft/ft_atoi.c
        fillit/figures_list.c
        libft/ft_sqrt.c)