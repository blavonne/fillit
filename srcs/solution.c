/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 19:21:19 by blavonne          #+#    #+#             */
/*   Updated: 2019/11/05 11:07:00 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	*insert_figure(int position, t_solution **shead, char *height,
		int *code)
{
	int		j;
	int		*insertion;

	if (!(insertion = (int *)malloc(sizeof(int) * 4)))
		return (NULL);
	j = 0;
	while (j < 4 && code[j] + (position - code[0]) < (*shead)->board_len *
	(*shead)->board_len && (*shead)->board[code[j] + (position - code[0])]
	== '.')
	{
		insertion[j] = code[j] + (position - code[0]);
		j++;
	}
	if (j == 4 && check_insertion_coherence((*shead)->board_len, insertion,
			height))
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

char		*generate_solution(t_figure **fhead, t_solution **shead)
{
	t_figure	*cur_figure;
	char		*cur_board;
	int			*insertion;

	if (!(*shead) || !(cur_figure = (*fhead)))
		return (NULL);
	while (cur_figure)
	{
		cur_board = (*shead)->board;
		while (cur_figure->position < (int)ft_strlen(cur_board) &&
		!(insertion = insert_figure(cur_figure->position, shead,
				cur_figure->height, cur_figure->code)))
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
