/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:09:03 by blavonne          #+#    #+#             */
/*   Updated: 2019/10/08 21:56:45 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_coherence(int board_len, int *insertion)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		if (insertion[i] % board_len == board_len - 1 &&
			!(insertion[i + 1] % board_len))
			return (0);
		if (insertion[i + 1] == insertion[i] + 1 ||\
		insertion[i + 1] == insertion[i] - 1 ||\
		insertion[i + 1] == insertion[i] + board_len - 1 ||\
		insertion[i + 1] == insertion[i] + board_len ||\
		insertion[i + 1] == insertion[i] + board_len - 2)
			i++;
		else
			return (0);
	}
	return (1);
}

int 	check_fg_qq(char **figures)
{
	int 	i;
	int		sharps;
	int 	points;
	char 	*tmp;

	tmp = *figures;
	if (!tmp || ft_strlen(tmp) < 16 || ft_strlen(tmp) % 4 != 0
		|| ft_strlen(tmp) > (4 * 4 * 26))
		return (0);
	while (*tmp)
	{
		i = 0;
		sharps = 0;
		points = 0;
		while (i++ < 16)
		{
			if (*tmp == '#' && sharps < 4)
				sharps++;
			if (*tmp == '.')
				points++;
			tmp++;
		}
		if (sharps != 4 || points + sharps != 16)
			return (0);
	}
	return (1);
}

int		check_fg_coherence(char **figures)
{
	int 	i;
	char 	*start;

	start = *figures;
	i = 0;
	while (start[i])
	{
		while (i < 16 && (start[i] == '.' || (start[i] == '#' &&\
		((start[i + 1] && start[i + 1] == '#') ||\
		(start[i - 1] && start[i - 1] == '#') ||\
		(start[i + 4] && start[i + 4] == '#') ||\
		(start[i - 4] && start[i - 4] == '#')))))
			i++;
		if (i == 16)
		{
			start = &start[i];
			i = 0;
		}
		else
			return (0);
	}
	return (1);
}

void	put_error(void)
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
	ft_put_errmsg("....\n#...\n#...\n##..");
}
