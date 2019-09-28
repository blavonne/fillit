/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 17:37:41 by blavonne          #+#    #+#             */
/*   Updated: 2019/09/28 21:07:00 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int main(int argc, char **argv)
{
	char		*figures;
	t_figure	*head;
	int 		board;
	int 	i = 0;

	if (full_validation(argv[1], &figures))
	{
		board = get_board_len(figures);
		printf("Board len: %d\n", board);
		while (i++ < 4)
			head = create_fg(&head, board);
		set_code(&head, figures, board);
		display_code(head);
	}
	return 0;
}