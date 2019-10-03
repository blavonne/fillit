/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solutions_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:15:37 by blavonne          #+#    #+#             */
/*   Updated: 2019/10/01 18:00:16 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_solution	*create_solution_head(t_figure *fhead, char *board)
{
	t_solution	*shead;

	if (!(shead = (t_solution *)malloc(sizeof(t_solution))))
		return (NULL);
	shead->lvl = 0;
	shead->board = board;
	shead->head = fhead;
	shead->current = fhead;
	shead->up = NULL;
	shead->down = NULL;
	shead->fg_position = board;
	return (shead);
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
			&& !(insertion = insert_figure("найти индексы, куда можно вставить")))
				cur_figure->position++;
			if (insertion)
			{
				cur_solution = add_solution("создать листик, внести буквы по индексам на карту");
				free(insertion);
				cur_figure->position++;
				cur_figure = cur_figure->next;
			}
			else
			{
				cur_figure = cur_figure->prev;
				cur_solution->board = NULL;
			}

		}
		free(cur_board);
	}
	return (cur_solution->board);
}