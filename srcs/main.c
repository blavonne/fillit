/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 17:37:41 by blavonne          #+#    #+#             */
/*   Updated: 2019/10/18 00:28:55 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static void	display_solve(char *solve, int board_len)
{
	int		i;

	if (!solve || !*solve)
		return ;
	while (*solve)
	{
		i = 0;
		while (i < board_len)
			ft_putchar(solve[i++]);
		ft_putchar('\n');
		solve = solve + board_len;
	}
}

static int	get_board_len(char **figures)
{
	int		i;

	i = 0;
	while (!ft_sqrt((int)ft_strlen(*figures) / 4 + i))
		i++;
	return (ft_sqrt((int)ft_strlen(*figures) / 4 + i));
}

static void	put_usage(void)
{
	ft_put_errmsg("Herzlich willcommen!\nTo run the program your ");
	ft_put_errmsg("figures map should be valid. Make sure,\n");
	ft_put_errmsg("a) you read only one file;\n");
	ft_put_errmsg("b) the file you read exists;\n");
	ft_put_errmsg("c) every figure \"lives\" in it's own square 4x4;\n");
	ft_put_errmsg("d) this square consists of \".\" and \"#\"\n");
	ft_put_errmsg("and all lines are followed by \"\\n\";\n");
	ft_put_errmsg("e) there are only 4 coherent \"#\" in one square;\n");
	ft_put_errmsg("f) quantity of figures is less than 27.\n");
	ft_put_errmsg("Here's the example:\n");
	ft_put_errmsg("....\n#...\n#...\n##..\n");
}

static void	validation(int argc, char **argv, char **figures)
{
	if (argc != 2)
	{
		put_usage();
		exit(1);
	}
	if (!(*figures = open_and_read(argv[1])))
	{
		ft_putstr("error\n");
		exit(2);
	}
}

int			main(int argc, char **argv)
{
	char		*figures;
	char		*solve;
	int			board_len;
	t_solution	*shead;
	t_figure	*fhead;

	shead = NULL;
	fhead = NULL;
	validation(argc, argv, &figures);
	board_len = get_board_len(&figures);
	while (prepare_input(&figures, &shead, &fhead, board_len)
		&& !(solve = generate_solution(board_len, &fhead, &shead)))
	{
		board_len++;
		clean_all(&shead, &fhead);
	}
	display_solve(solve, board_len);
	clean_all(&shead, &fhead);
	free(figures);
	return (1);
}
