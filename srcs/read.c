/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 17:15:21 by blavonne          #+#    #+#             */
/*   Updated: 2019/10/18 00:24:16 by blavonne         ###   ########.fr       */
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

	l = 1;
	figures = ft_strnew(0);
	tmp = NULL;
	fd = open(argv, O_RDONLY);
	while ((figures_ptr = figures) && get_next_line(fd, &tmp) > 0 && l++)
	{
		figures = ft_strjoin(figures, tmp);
		free(figures_ptr);
		free(tmp);
	}
	free(tmp);
	if (l != ft_strlen(figures) / 16 * 5)
	{
		close(fd);
		free(figures);
		return (NULL);
	}
	close(fd);
	return (figures);
}
