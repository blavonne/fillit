/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 19:21:19 by blavonne          #+#    #+#             */
/*   Updated: 2019/10/18 01:45:19 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static int	*insert_figure(int position, char **board, int board_len, int *code)
{
	int		j;
	int		*insertion;

	if ((position == 0 && (code[0] == 1 || code[0] == 2)) ||
		(position == 1 && code[0] == 2))
		return (NULL);
	if (!(insertion = (int *)malloc(sizeof(int) * 4)))
		return (NULL);
	j = 0;
	while (j < 4 && (*board)[code[j] + (position - code[0])] == '.')
	{
		insertion[j] = code[j] + (position - code[0]);
		j++;
	}
	if (board_len == 3 && code[0] == 2 && insertion[0] % board_len != 2)
		return (NULL);
	if (j == 4 && check_insertion_coherence(board_len, insertion))
		return (insertion);
	else
	{
		free(insertion);
		return (NULL);
	}
}

static int	step_back(t_solution **shead, t_figure **cur_fg)
{
	t_solution	*tmp;

	(*cur_fg)->position = 0;
	(*cur_fg) = (*cur_fg)->prev;
	if ((*shead)->lvl < 1)
		return (0);
	else
	{
		tmp = (*shead)->up;
		free((*shead)->board);
		free(*shead);
		(*shead) = tmp;
	}
	return (1);
}

static int	add_solution(int **insertion, t_figure **cur_fg,
		t_solution **shead, char *cur_board)
{
	t_solution	*new;
	int			i;

	i = 0;
	if (!(new = (t_solution *)malloc(sizeof(t_solution))))
		return (0);
	if (!(new->board = ft_strdup(cur_board)))
	{
		free(*insertion);
		free(new);
		return (0);
	}
	while (i < 4)
		new->board[(*insertion)[i++]] = (*cur_fg)->letter;
	new->board_len = (*shead)->board_len;
	new->lvl = (*cur_fg)->letter - 'A' + 1;
	new->up = (*shead);
	(*shead) = new;
	free(*insertion);
	(*cur_fg)->position++;
	(*cur_fg) = (*cur_fg)->next;
	return (1);
}

char		*generate_solution(int board_len, t_figure **fhead,
		t_solution **shead)
{
	t_figure	*cur_figure;
	char		*cur_board;
	int			*insertion;

	if (!(*shead) || !(cur_figure = (*fhead)))
		return (NULL);
	while (cur_figure)
	{
		if (cur_figure->width > board_len)
			return (NULL);
		cur_board = (*shead)->board;
		while (cur_figure->position < (int)ft_strlen(cur_board) &&
		!(insertion = insert_figure(cur_figure->position, &cur_board,
				board_len, cur_figure->code)))
			cur_figure->position++;
		if (insertion)
			add_solution(&insertion, &cur_figure, shead, cur_board);
		else
		{
			if (!step_back(shead, &cur_figure))
				return (NULL);
		}
	}
	return ((*shead)->board);
}
