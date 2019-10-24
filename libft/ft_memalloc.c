/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:44:01 by blavonne          #+#    #+#             */
/*   Updated: 2019/10/24 19:43:00 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*obj;

	obj = 0;
	if (!(obj = malloc(size)))
		return (NULL);
	ft_memset(obj, 0, size);
	return (obj);
}
