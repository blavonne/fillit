/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 17:15:21 by blavonne          #+#    #+#             */
/*   Updated: 2019/10/01 16:38:31 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include "fillit.h"
#include <stdio.h>

char 	*read_file(char *argv)
{
	char 	*tmp;
	char	*figures;
	char	*figures_ptr;
	int 	fd;
	int 	count_lines;

	count_lines = 1;
	if (!(figures = ft_strnew(0)))
		return (NULL);
	tmp = NULL;
	fd = open("/Users/blavonne/CLionProjects/fillit/fillit/qwerty", O_RDONLY);
	while (get_next_line(fd, &tmp) > 0 && count_lines++)
	{
		figures_ptr = figures;
		if (!(figures = ft_strjoin(figures, tmp)))
		{
			free(figures_ptr);
			return (NULL);
		}
		free(figures_ptr);
		free(tmp);
	}
	if (count_lines != ft_strlen(figures) / 16 * 5)
		return (NULL);
	printf("The line:\n%s\n", figures);
	close(fd);
	return (figures);
}

int 	check_figures(char *figures)
{
	int 	i;
	int		sharps;
	int 	points;

	if (!figures || ft_strlen(figures) < 16 || ft_strlen(figures) % 4 != 0)
		return (0);
	while (*figures)
	{
		i = 0;
		sharps = 0;
		points = 0;
		while (i++ < 16)
		{
			if (*figures == '#' && sharps < 4)
				sharps++;
			if (*figures == '.')
				points++;
			figures++;
		}
		if (points + sharps != 16)
			return (0);
	}
	printf("Check figures is perfect!\n");
	return (1);
}

int		validate_figures(char *figures)
{
	int 	i;
	char 	*start;

	start = figures;
	i = 0;
	while (i < 16 && *start)
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
	printf("Figures are valid!\n");
	return (1);
}

int		full_validation(char *argv, char **figures)
{
	if ((*figures = read_file(argv)) && check_figures(*figures) && validate_figures(*figures))
		return (1);
	return (0);
}

int 	get_board_len(char *figures)
{
	int 	i;

	i = 0;
	while (!ft_sqrt((int)ft_strlen(figures) / 4 + i))
		i++;
	return (ft_sqrt((int)ft_strlen(figures) / 4 + i));
}