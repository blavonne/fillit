/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 18:08:43 by blavonne          #+#    #+#             */
/*   Updated: 2019/10/09 21:22:20 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*buf;

	if (!s || !(buf = ft_strnew(len)))
		return (NULL);
	if (!(buf = ft_strncpy(buf, &s[start], len)))
		return (NULL);
	return (buf);
}
