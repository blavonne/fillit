/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:09:03 by blavonne          #+#    #+#             */
/*   Updated: 2019/10/24 17:35:45 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		check_insertion_coherence(int len, int *ins)
{
	int		i;
	int		j;
	int		count;

	i = -1;
	count = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (ins[i] == ins[j] + 1 || ins[i] == ins[j] - 1 || ins[i] ==
																ins[j] + len || ins[i] == ins[j] - len)
				count++;
			if ((len > 3 && ins[i] == ins[j] - 1 && ins[i] % len == len - 1
				 && !(ins[j] % len)))
				return (0);
		}
	}
	if (count >= 6 && !(count % 2))
		return (1);
	return (0);
}
