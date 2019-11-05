/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:55:49 by azomega           #+#    #+#             */
/*   Updated: 2019/10/29 18:12:31 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		ft_freedellst(t_list **fd_lst, int fd)
{
	t_list	*prev;
	t_list	*head;

	prev = NULL;
	head = *fd_lst;
	while (head)
	{
		if (head->content_size == (size_t)fd)
		{
			if (prev)
				prev->next = head->next;
			else
				*fd_lst = head->next;
			ft_strdel((char **)&(head->content));
			head->content_size = 0;
			free(head);
			return ;
		}
		prev = head;
		head = head->next;
	}
}

static t_list	*ft_find_fd(t_list **fd_lst, int fd)
{
	t_list	*head;
	t_list	*new;
	t_list	*fd_found;

	if (!fd_lst)
		return (NULL);
	head = *fd_lst;
	while (head)
	{
		if (head->content_size == (size_t)fd)
			return (fd_found = head);
		head = head->next;
	}
	if (!(new = ft_lstnew("", 1)))
		return (NULL);
	new->content_size = fd;
	ft_lstadd(fd_lst, new);
	return (*fd_lst);
}

static int		ft_read_one_line(t_list *fd_found, char **line, const int fd)
{
	char	buf[BUFF_SIZE + 1];
	size_t	rd;
	char	*tmp;
	char	*ret;

	rd = 1;
	while (rd > 0)
	{
		if ((ret = ft_strchr(fd_found->content, '\n')))
			*ret++ = '\0';
		if (!(tmp = ft_strjoin(*line, fd_found->content)))
			return (-1);
		free(*line);
		*line = tmp;
		if (ret && !(ret = ft_strdup(ret)))
			return (-1);
		free(fd_found->content);
		if ((fd_found->content = ret))
			return (1);
		rd = read(fd, buf, BUFF_SIZE);
		if (!(fd_found->content = ft_strsub(buf, 0, rd)))
			return (-1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*fd_lst = 0;
	t_list			*fd_found;
	int				retval;

	if (fd < 0 || !line || read(fd, NULL, 0) == -1)
		return (-1);
	if (!(*line = ft_strnew(0)))
		return (-1);
	if (!(fd_found = ft_find_fd(&fd_lst, fd)))
		return (-1);
	if ((retval = ft_read_one_line(fd_found, line, fd)) == 0)
	{
		if (ft_strlen(*line) > 0)
			return (1);
		ft_freedellst(&fd_lst, fd);
	}
	return (retval);
}
