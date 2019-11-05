/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 09:58:04 by blavonne          #+#    #+#             */
/*   Updated: 2019/11/05 09:58:04 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*generate_board(int board_len)
{
	char	*board;

	if (!(board = ft_strnew(board_len * board_len)))
		return (NULL);
	board = ft_memset(board, '.', board_len * board_len);
	return (board);
}

static int	count_figures(char **figures)
{
	return ((int)ft_strlen(*figures) / 16);
}

static void	del_all_fgs(t_figure **fhead)
{
	t_figure	*phead;
	t_figure	*tmp;

	phead = *fhead;
	while (phead)
	{
		tmp = phead->next;
		free(phead->code);
		free(phead);
		phead = tmp;
	}
	free(fhead);
}

int			prepare_input(char **figures, t_solution **shead, t_figure **fhead,
		int board_len)
{
	int		i;
	char	*board;

	i = 0;
	while (i++ < count_figures(figures))
	{
		if (!(create_fg(fhead)))
		{
			del_all_fgs(fhead);
			*fhead = NULL;
			return (0);
		}
	}
	if (!set_code(fhead, *figures, board_len) ||
	!(board = generate_board(board_len)))
		return (0);
	if (!(*shead = create_solution_head(board, board_len)))
		return (0);
	return (1);
}

void		clean_all(t_solution **shead, t_figure **fhead)
{
	t_solution	*stmp;
	t_figure	*ftmp;

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
