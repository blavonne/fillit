/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 17:37:41 by blavonne          #+#    #+#             */
/*   Updated: 2019/10/11 17:40:14 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int main(int argc, char **argv)
{
	char	*figures;
	char	*solve;
	int 	board_len;
	t_solution	*shead;
	t_figure	*fhead;

	shead = NULL;
	fhead = NULL;
	if (argc != 2 || !(figures = read_file(argv[1])) ||
	!check_fg_qq(&figures) || !check_fg_coherence(&figures))
	{
		put_error();
		return (0);
	}
	board_len = get_board_len(&figures);
		while (prepare_input(&figures, &shead, &fhead, board_len) &&
		!(solve = generate_solution(board_len, &fhead, &shead)))
		{
			board_len++;
			clean_all(&shead, &fhead);
		}
	display_solve(solve, board_len);
	clean_all(&shead, &fhead);
	free(figures);
	return (1);
}