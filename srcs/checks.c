/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:09:03 by blavonne          #+#    #+#             */
/*   Updated: 2019/11/05 11:24:06 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_insertion_coherence(int len, int *ins, char *height)
{
	int		i;
	int		j;

	i = 0;
	while (i + 1 < 4)
	{
		j = i + 1;
		if (ins[i] % len == len - 1 && !(ins[j] % len))
			if (ins[0] / len - ins[1] / len + '0' != height[0] || ins[0] /
			len - ins[2] / len + '0' != height[1] || ins[0] / len - ins[3] /
			len + '0' != height[2])
				return (0);
		i++;
	}
	return (1);
}
