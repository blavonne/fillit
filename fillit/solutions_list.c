/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solutions_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:15:37 by blavonne          #+#    #+#             */
/*   Updated: 2019/10/07 16:34:24 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_solution	*create_solution_head(t_figure *fhead, char *board, int board_len)
{
	t_solution	*shead;

	if (!(shead = (t_solution *)malloc(sizeof(t_solution))))
		return (NULL);
	shead->lvl = 0;
	shead->board = board;
	shead->up = NULL;
	shead->down = NULL;
	shead->board_len = board_len;
	return (shead);
}

int 	check_coherence(int board_len, int *insertion)
{
	int 	i;

	i = 0;
	while (i < 3)
	{
		if (insertion[i] % board_len == board_len - 1 && !(insertion[i + 1] % board_len))
			return (0);
		if (insertion[i + 1] == insertion[i] + 1 ||\
		insertion[i + 1] == insertion[i] - 1 ||\
		insertion[i + 1] == insertion[i] + board_len - 1 ||\
		insertion[i + 1] == insertion[i] + board_len ||\
		insertion[i + 1] == insertion[i] + board_len - 2)
			i++;
		else
			return (0);
	}
	return (1);
}

int 	*insert_figure(int position, char *board, int board_len, int *code)
{
	int 	j;
	int 	*insertion;

	if (position == 0 && code[0] == 1)
		return (NULL);
	if (!(insertion = (int *)malloc(sizeof(int) * 4)))
		return (0);
	j = 0;
	while (j < 4 && board[code[j] + (position - code[0])] == '.')
	{
		insertion[j] = code[j] + (position - code[0]);
		j++;
	}
	if (j == 4 && check_coherence(board_len, insertion))
		return (insertion);
	else
	{
		free(insertion);
		return (NULL);
	}
}

t_solution	*add_solution(int *insertion, t_figure *cur_fg, t_solution **shead, char *cur_board)
{
	t_solution	*new;
	int 		i;

	i = 0;
	if (!(new = (t_solution *)malloc(sizeof(t_solution))))
		return (NULL);
	while (i < 4)
		cur_board[insertion[i++]] = cur_fg->letter;
	if (!(new->board = ft_strdup(cur_board)))
	{
		free(cur_board);
		free(new);
		return (NULL);
	}
	free(cur_board);
	new->board_len = (*shead)->board_len;
	new->lvl = cur_fg->letter - 'A' + 1;
	(*shead)->down = new;
	new->up = (*shead);
	new->down = NULL;
	(*shead) = new;
	return (*shead);
}

t_solution	*step_back(t_solution **head)
{
	t_solution *tmp;

	tmp = (*head)->up;
	free((*head)->board);
	free(*head);
	(*head) = tmp;
	return (*head);
}

char	*generate_solution(int board_len, t_figure *fhead, t_solution *shead)
{
	t_figure	*cur_figure;
	t_solution	*cur_solution;
	char 		*cur_board;
	int 		*insertion;

	if (!shead || !fhead)
		return ("404");
	cur_figure = fhead;
	cur_solution = shead;
	while (cur_figure)
	{
		cur_board = ft_strdup(cur_solution->board);
		if (cur_board)
		{
			while (cur_figure->position < ft_strlen(cur_board)\
			&& !(insertion = insert_figure(cur_figure->position, cur_board, board_len,\
			cur_figure->code)))
				cur_figure->position++;
			if (insertion)
			{
				cur_solution = add_solution(insertion, cur_figure, &shead, cur_board);
				free(insertion);
				insertion = NULL;
				cur_figure->position++;
				cur_figure = cur_figure->next;
			}
			else
			{
				cur_figure->position = 0;
				if (cur_figure->letter == 'A')
					return (NULL);
				cur_figure = cur_figure->prev;
				if (cur_solution->up == shead)
					return (NULL);
				else
					cur_solution = step_back(&shead);
			}
		}
	}
	return (cur_solution->board);
}