/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 17:35:15 by blavonne          #+#    #+#             */
/*   Updated: 2019/10/08 21:49:50 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"

char	*read_file(char *argv);
int 	check_fg_qq(char **figures);
int		check_fg_coherence(char **figures);
int 	get_board_len(char **figures);
int 	count_figures(char **figures);
char	*generate_board(int board_len);


typedef struct		s_figure
{
	char			letter;
	int				*code;
	int 			position;
	struct s_figure	*next;
	struct s_figure	*prev;
}					t_figure;

t_figure	*create_fg(t_figure **fhead);
int			*get_code(const char *figure);
int			*move_up_left(int *code);
int			set_code(t_figure **head, char *figures, int board_len);
void		lst_clean(t_figure **head);
void		ft_fg_addback(t_figure **head, t_figure *new);

typedef struct			s_solution
{
	char				*board;
	int 				lvl;
	struct s_solution	*up;
	int 				board_len;
}						t_solution;

t_solution	*create_solution_head(t_figure *fhead, char *board, int board_len);

char		*generate_solution(int board_len, t_figure **fhead,
			t_solution **shead);
int			check_coherence(int board_len, int *insertion);
int			get_solution(char *argv);
void		clean_all(t_solution **shead, t_figure **fhead, char **solve);
int			prepare_input(char **figures, t_solution **shead, t_figure **fhead,
			int board_len);
void		display_solve(char *solve, int board_len);
void		put_error(void);

#endif
