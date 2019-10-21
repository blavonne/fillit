/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:09:03 by blavonne          #+#    #+#             */
/*   Updated: 2019/10/21 13:18:54 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		check_insertion_coherence(int len, int *ins)
{
	int		i;
	int		j;
	int		count;

	i = -1;
	count = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (ins[i] == ins[j] + 1 || ins[i] == ins[j] - 1 || ins[i] ==
			ins[j] + len || ins[i] == ins[j] - len)
				count++;
			if ((len > 3 && ins[i] == ins[j] - 1 && ins[i] % len == len - 1
			&& !(ins[j] % len)))
				return (0);
		}
	}
	if (count >= 6 && !(count % 2))
		return (1);
	return (0);
}

int		check_fg_qq(char **figures)
{
	int		i;
	int		sharps;
	int		points;
	char	*tmp;

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
			if (*tmp++ == '.')
				points++;
		}
		if (sharps != 4 || points + sharps != 16)
			return (0);
	}
	return (1);
}

int		check_fg_coherence(char **figures)
{
	int		i;
	char	*start;

	start = *figures;
	i = 0;
	while (start[i])
	{
		while (i < 16 && (start[i] == '.' || (start[i] == '#' && ((start[i +
		1] && start[i + 1] == '#') || (start[i - 1] && start[i - 1] == '#')
		|| (start[i + 4] && start[i + 4] == '#') || (start[i - 4] && start[i
		- 4] == '#')))))
			i++;
		if (i == 16)
		{
			start = &start[i];
			i = 0;
		}
		else
			return (0);
	}
	if (((*figures)[17] == '#' && (*figures)[21] == '#' && (*figures)[26] ==
	'#' && (*figures)[30] == '#') || ((*figures)[5] == '#' && (*figures)[6]
	== '#' && (*figures)[13] == '#' && (*figures)[14] == '#'))
		return (0);
	return (1);
}
