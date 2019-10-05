/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 19:20:14 by blavonne          #+#    #+#             */
/*   Updated: 2019/10/01 16:11:03 by blavonne         ###   ########.fr       */
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

char	*find_place(const char *board, t_figure *figure)
{
	int 		i;
	int 		j;
	int 		diff;
	t_figure	*tmp;

	i = 0;
	j = 0;
	diff = 0;
	tmp = (t_figure *)malloc(sizeof(t_figure));
	tmp = ft_memcpy(tmp, figure, sizeof(t_figure));
	while (board[i])
	{
		if (board[i] == '0')
		{
			diff = i - tmp->code[0];
			tmp->code[0] += diff;
			tmp->code[1] += diff;
			tmp->code[2] += diff;
			tmp->code[3] += diff;
			while (j < 4)
			{
				if (board[(tmp->code[j++])] != '0')
					break ;
			}
		}
	}
}

