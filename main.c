/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 17:37:41 by blavonne          #+#    #+#             */
/*   Updated: 2019/10/08 18:18:54 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int main(int argc, char **argv)
{
	get_solution(argv[1]);

//	char		*figures;
//	t_figure	*fhead;
//	int 		board_len;
//	int 		i;
//	char 		*board;
//	t_solution	*shead;
//	char		*solve;
//
//	i = 0;
//	if (full_validation(argv[1], &figures))
//	{
//		board_len = get_board_len(figures);
//		printf("Board board_len: %d\n", board_len);
//		while (i++ < count_figures(figures))
//		{
//			if (!(fhead = create_fg(&fhead, board_len)))
//			{
//				lst_clean(&fhead);
//				return (-1);
//			}
//		}
//		set_code(&fhead, figures, board_len);
//		display_code(fhead);
//		if (!(board = generate_board(board_len)))
//			return (-1);
//		if (!(shead = create_solution_head(fhead, board, board_len)))
//			return (-1);
//		while (!(solve = generate_solution(board_len, fhead, shead)))
//		{
//			board_len++;
//			free(solve);
//			free(fhead);
//			free(shead);
//			solve = NULL;
//			fhead = NULL;
//			shead = NULL;
//			i = 0;
//			while (i++ < count_figures(figures))
//			{
//				if (!(fhead = create_fg(&fhead, board_len)))
//				{
//					lst_clean(&fhead);
//					return (-1);
//				}
//			}
//			set_code(&fhead, figures, board_len);
//			display_code(fhead);
//			if (!(board = generate_board(board_len)))
//				return (-1);
//			if (!(shead = create_solution_head(fhead, board, board_len)))
//				return (1);
//		}
//	}
//	int j = 0;
//	while (solve[j])
//	{
//		if (j % board_len == 0)
//		printf("\n");
//		printf("%c", solve[j]);
//		j++;
//	}
	return (0);
}