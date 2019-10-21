/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 10:37:01 by blavonne          #+#    #+#             */
/*   Updated: 2019/10/21 13:18:54 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int		res;

	res = 0;
	if (nb < 0)
		return (0);
	while ((res * res) <= nb && res * res >= 0)
	{
		if ((res * res) == nb)
			return (res);
		res++;
	}
	return (0);
}
