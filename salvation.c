/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 19:20:14 by blavonne          #+#    #+#             */
/*   Updated: 2019/10/08 20:29:59 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*generate_board(int board_len)
{
	char	*board;

	if (!(board = ft_strnew(board_len * board_len)))
		return (NULL);
	board = ft_memset(board, '.', board_len * board_len);
	return (board);
}

int		prepare_input(char **figures, t_solution **shead, t_figure **fhead,
		int board_len)
{
	int		i;
	char 	*board;

	i = 0;
	while (i++ < count_figures(figures))
	{
		if (!(*fhead = create_fg(fhead)))
		{
			lst_clean(fhead);
			return (0);
		}
	}
	set_code(fhead, *figures, board_len);
	if (!(board = generate_board(board_len)))
		return (0);
	if (!(*shead = create_solution_head(*fhead, board, board_len)))
		return (0);
	return (1);
}

void	clean_all(t_solution **shead, t_figure **fhead, char **solve)
{
	t_solution	*stmp;
	t_figure	*ftmp;

	free(*solve);
	*solve = NULL;
	while (*shead)
	{
		stmp = *shead;
		(*shead) = (*shead)->up;
		free(stmp->board);
		free(stmp);
	}
	*shead = NULL;
	while (*fhead)
	{
		ftmp = *fhead;
		(*fhead) = (*fhead)->next;
		free(ftmp->code);
		free(ftmp);
	}
	*fhead = NULL;
}

void	display_solve(char *solve, int board_len)
{
	int 	i;

	while (*solve)
	{
		i = 0;
		while (i < board_len)
			ft_putchar(solve[i++]);
		ft_putchar('\n');
		solve = solve + board_len;
	}
}

int		get_solution(char *argv)
{
	char	*figures;
	char	*solve;
	int 	board_len;
	t_solution	*shead;
	t_figure	*fhead;

	shead = NULL;
	fhead = NULL;
	if (!(figures = read_file(argv)) || !check_fg_qq(&figures) || !check_fg_coherence(&figures))
	{
		put_error();
		return (0);
	}
	if (prepare_input(&figures, &shead, &fhead, get_board_len(&figures)))
	{
		board_len = shead->board_len;
		while (!(solve = generate_solution(board_len, &fhead, &shead)))
		{
			board_len++;
			clean_all(&shead, &fhead, &solve);
			prepare_input(&figures, &shead, &fhead, board_len);
		}
		display_solve(solve, board_len);
		return (1);
	}
	return (0);
}
