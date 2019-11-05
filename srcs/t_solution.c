/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_solution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 09:58:52 by blavonne          #+#    #+#             */
/*   Updated: 2019/11/05 09:58:52 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_solution	*create_solution_head(char *board, int board_len)
{
	t_solution	*shead;

	if (!(shead = (t_solution *)malloc(sizeof(t_solution))))
		return (NULL);
	shead->lvl = 0;
	shead->board = board;
	shead->up = NULL;
	shead->board_len = board_len;
	return (shead);
}
