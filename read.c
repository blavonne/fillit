/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 17:15:21 by blavonne          #+#    #+#             */
/*   Updated: 2019/10/08 20:10:24 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
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
	fd = open("/Users/blavonne/CLionProjects/fillit/qwerty2", O_RDONLY);
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
	close(fd);
	return (figures);
}

int 	get_board_len(char **figures)
{
	int 	i;

	i = 0;
	while (!ft_sqrt((int)ft_strlen(*figures) / 4 + i))
		i++;
	return (ft_sqrt((int)ft_strlen(*figures) / 4 + i));
}