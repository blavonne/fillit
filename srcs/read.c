/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 09:58:23 by blavonne          #+#    #+#             */
/*   Updated: 2019/11/05 09:58:23 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <stdlib.h>

static size_t	check_line(size_t n, char *str, size_t *num)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(str);
	i = 0;
	if ((n + 1) % 5 != 0)
	{
		if (len != 4 || *num > 4)
			return (0);
		while (i++ < 4)
			if (str[i - 1] != '.')
			{
				if (str[i - 1] == '#')
					(*num)++;
				else
					return (0);
			}
	}
	if ((((n + 1) % 5 == 0) && len != 0) || ((n + 1) % 5 == 4 && *num != 4))
		return (0);
	return (1);
}

static size_t	check_position(char *str)
{
	size_t	i;
	size_t	s;

	i = 0;
	s = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#' && (i > 3) && (str[i - 4] == '#'))
			s++;
		if (str[i] == '#' && (i < 12) && (str[i + 4] == '#'))
			s++;
		if (str[i] == '#' && (i % 4 != 0) && (str[i - 1] == '#'))
			s++;
		if (str[i] == '#' && (i + 1) % 4 != 0 && (str[i + 1] == '#'))
			s++;
		if (++i == 16)
		{
			if (s != 6 && s != 8)
				return (0);
			s = 0;
			i = 0;
			str += 16;
		}
	}
	return (1);
}

static char		*free_and_ret(char **ret, char **buf)
{
	free(*ret);
	free(*buf);
	return (NULL);
}

static char		*read_and_check(int fd)
{
	char	*ret;
	char	*tmp;
	char	*buf;
	size_t	n;
	size_t	num;

	n = 0;
	ret = ft_strnew(0);
	while (get_next_line(fd, &buf) > 0)
	{
		if (n % 5 == 0)
			num = 0;
		if (!check_line(n, buf, &num))
			return (free_and_ret(&ret, &buf));
		n++;
		tmp = ret;
		ret = ft_strjoin(ret, buf);
		free(buf);
		free(tmp);
	}
	if (ft_strlen(ret) % 16 || n % 5 != 4 || n > 129)
		return (free_and_ret(&ret, &buf));
	free(buf);
	return (ret);
}

char			*open_and_read(char *av)
{
	int		fd;
	char	*ret;

	if ((fd = open(av, O_RDONLY)) == -1)
		return (NULL);
	if (!(ret = read_and_check(fd)) || !check_position(ret))
		return (NULL);
	return (ret);
}
