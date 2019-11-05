/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:28:33 by blavonne          #+#    #+#             */
/*   Updated: 2019/11/05 15:28:33 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		clean_all(t_solution **shead, t_figure **fhead)
{
	t_solution	*stmp;
	t_figure	*ftmp;

	while (*shead)
	{
		stmp = *shead;
		(*shead) = (*shead)->up;
		free(stmp->board);
		free(stmp);
	}
	*shead = NULL;
	while (*fhead)
	{
		ftmp = *fhead;
		(*fhead) = (*fhead)->next;
		free(ftmp->code);
		free(ftmp->height);
		free(ftmp);
	}
	*fhead = NULL;
}
