/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 17:15:21 by blavonne          #+#    #+#             */
/*   Updated: 2019/10/21 13:09:56 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "../includes/fillit.h"

char	*read_file(char *argv)
{
	char	*tmp;
	char	*figures;
	char	*figures_ptr;
	int		fd;
	int		l;

	l = 0;
	figures = ft_strnew(0);
	tmp = NULL;
	fd = open("/Users/blavonne/CLionProjects/fillit/qwerty", O_RDONLY);
	while (++l && (figures_ptr = figures) && get_next_line(fd, &tmp) > 0)
	{

		figures = ft_strjoin(figures, tmp);
		free(figures_ptr);
		if (!ft_strlen(tmp) && l % 5)
		{
			free(tmp);
			close(fd);
			free(figures);
			return (NULL);
		}
		free(tmp);
	}
	close(fd);
	free(tmp);
	if (l != ft_strlen(figures) / 16 * 5)
	{
		free(figures);
		return (NULL);
	}
	return (figures);
}
