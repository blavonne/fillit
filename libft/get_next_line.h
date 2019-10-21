/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:30:10 by blavonne          #+#    #+#             */
/*   Updated: 2019/10/21 13:18:54 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_GET_NEXT_LINE_H
# define GET_NEXT_LINE_GET_NEXT_LINE_H
# define BUFF_SIZE 4

# include <sys/uio.h>
# include <stdlib.h>
# include "../libft/libft.h"

int					get_next_line(const int fd, char **line);

typedef struct		s_buff
{
	int				fd;
	char			*buff;
}					t_buff;

#endif
