/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 17:35:15 by blavonne          #+#    #+#             */
/*   Updated: 2019/09/28 21:08:53 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/libft.h"
# include "get_next_line.h"

char	*read_file(char *argv);
int 	check_figures(char *figures);
int		validate_figures(char *figures);
int		full_validation(char *argv, char **figures);
int 	get_board_len(char *figures);


typedef struct		s_figure
{
	char			letter;
	int				*code;
	int 			board_len;
	struct s_figure	*next;

}					t_figure;

t_figure	*create_fg(t_figure **head, int board_len);
int			*get_code(const char *figure);
int			*move_up_left(int *code);
int			set_code(t_figure **head, char *figures, int board_len);
void		display_code(t_figure *head);
void		lst_clean(t_figure **head);

#endif
