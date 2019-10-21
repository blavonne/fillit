/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solutions_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:15:37 by blavonne          #+#    #+#             */
/*   Updated: 2019/10/11 19:59:39 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

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
