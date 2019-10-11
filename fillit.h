/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 17:35:15 by blavonne          #+#    #+#             */
/*   Updated: 2019/10/11 20:05:05 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"

char					*read_file(char *argv);

int						check_fg_qq(char **figures);
int						check_fg_coherence(char **figures);
int						check_insertion_coherence(int board_len,
							int *insertion);

typedef struct			s_figure
{
	char				letter;
	int					*code;
	int					position;
	struct s_figure		*next;
	struct s_figure		*prev;
}						t_figure;

int						create_fg(t_figure **fhead);
int						set_code(t_figure **head, char *figures,
							int board_len);

typedef struct			s_solution
{
	char				*board;
	int					lvl;
	struct s_solution	*up;
	int					board_len;
}						t_solution;

t_solution				*create_solution_head(char *board, int board_len);

int						prepare_input(char **figures, t_solution **shead,
							t_figure **fhead, int board_len);
char					*generate_solution(int board_len, t_figure **fhead,
							t_solution **shead);
void					clean_all(t_solution **shead, t_figure **fhead);

#endif
