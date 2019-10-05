/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 17:37:41 by blavonne          #+#    #+#             */
/*   Updated: 2019/10/05 06:54:10 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int main(int argc, char **argv)
{
	char		*figures;
	t_figure	*head;
	int 		board_len;
	int 		i;
	char 		*board;
	t_solution	*solution_vector;
	char		*solve;

	i = 0;
	if (full_validation(argv[1], &figures))
	{
		board_len = get_board_len(figures);
		printf("Board board_len: %d\n", board_len);
		while (i++ < count_figures(figures))
		{
			if (!(head = create_fg(&head, board_len)))
			{
				lst_clean(&head);
				return (-1);
			}
		}
		set_code(&head, figures, board_len);
		display_code(head);
		if (!(board = generate_board(board_len)))
			return (-1);
		if (!(solution_vector = create_solution_head(head, board, board_len)))
			return (1);
		while (!(solve = generate_solution(board_len, head, solution_vector)) && board_len < 7)
		{
			board_len++;
			free(solve);
			free(head);
			free(solution_vector);
			solve = NULL;
			head = NULL;
			solution_vector = NULL;
			i = 0;
			while (i++ < count_figures(figures))
			{
				if (!(head = create_fg(&head, board_len)))
				{
					lst_clean(&head);
					return (-1);
				}
			}
			set_code(&head, figures, board_len);
			display_code(head);
			if (!(board = generate_board(board_len)))
				return (-1);
			if (!(solution_vector = create_solution_head(head, board, board_len)))
				return (1);
		}
		int j = 0;
		while (solve[j])
		{
			if (j % board_len == 0)
				printf("\n");
			printf("%c", solve[j]);
			j++;
		}
		//printf("%s\n", solve);
	}
	return (0);
}