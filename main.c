/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 17:37:41 by blavonne          #+#    #+#             */
/*   Updated: 2019/10/01 16:12:50 by blavonne         ###   ########.fr       */
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

	i = 0;
	if (full_validation(argv[1], &figures))
	{
		board_len = get_board_len(figures);
		printf("Board len: %d\n", board_len);
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

	}
	return 0;
}