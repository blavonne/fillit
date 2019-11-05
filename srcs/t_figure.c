/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_figure.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 09:58:40 by blavonne          #+#    #+#             */
/*   Updated: 2019/11/05 09:59:58 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		add_back_fg(t_figure **head, t_figure *new)
{
	t_figure	*phead;

	phead = *head;
	while (phead->next)
		phead = phead->next;
	new->prev = phead;
	phead->next = new;
}

int				create_fg(t_figure **fhead)
{
	t_figure	*figure;

	if (!*fhead)
	{
		if (!(figure = (t_figure *)malloc(sizeof(t_figure))))
			return (0);
		if (!(figure->code = (int *)malloc(sizeof(int) * 4)))
			return (0);
		figure->height = NULL;
		figure->next = NULL;
		figure->prev = NULL;
		figure->position = 0;
		*fhead = figure;
		return (1);
	}
	if (!(figure = (t_figure *)malloc(sizeof(t_figure))))
		return (0);
	if (!(figure->code = (int *)malloc(sizeof(int) * 4)))
		return (0);
	figure->next = NULL;
	figure->height = NULL;
	figure->position = 0;
	add_back_fg(fhead, figure);
	return (1);
}
