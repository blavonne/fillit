# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blavonne <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/13 18:35:48 by blavonne          #+#    #+#              #
#    Updated: 2019/10/18 01:45:19 by blavonne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ./srcs/checks.c ./srcs/figures_code.c ./srcs/main.c ./srcs/prepare.c\
	 ./srcs/read.c ./srcs/solution.c ./srcs/t_figure.c ./srcs/t_solution.c
OBJ = $(SRC:%.c=%.o)

INCLUDES = ./includes
LFT_DIR = ./libft

NAME = fillit

FLAGS = -Wall -Werror -Wextra -I $(INCLUDES) -I $(LFT_DIR)
LFLAGS = -L $(LFT_DIR) -lft

LIBFT = ./libft/libft.a

all: $(SRC) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	gcc $(OBJ) -o $(NAME) $(FLAGS) $(LFLAGS)

%.o: %.c
	gcc $(FLAGS) -c  $< -o $@

clean:
	$(MAKE) -C $(LFT_DIR) clean
	rm -rf $(OBJ)

fclean: clean
	$(MAKE) -C $(LFT_DIR) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
