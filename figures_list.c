/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fugures_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 17:44:25 by blavonne          #+#    #+#             */
/*   Updated: 2019/10/08 17:52:25 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_fg_addback(t_figure **head, t_figure *new)
{
	t_figure	*phead;

	phead = *head;
	while (phead->next)
		phead = phead->next;
	new->prev = phead;
	phead->next = new;
}

void		lst_clean(t_figure **head)
{
	t_figure	*phead;
	t_figure	*tmp;

	phead = *head;
	while (phead)
	{
		tmp = phead->next;
		free(phead->code);
		free(phead);
		phead = tmp;
	}
	free (head);
}

t_figure	*create_fg(t_figure **fhead, int board_len)
{
	t_figure	*figure;

	if (!*fhead)
	{
		if (!(figure = (t_figure *)malloc(sizeof(t_figure))))
			return (NULL);
		if (!(figure->code = (int *)malloc(sizeof(int) * 4)))
			return (NULL);
		figure->board_len = board_len;
		figure->next = NULL;
		figure->prev = NULL;
		figure->position = 0;
		*fhead = figure;
		return (*fhead);
	}
	if (!(figure = (t_figure *)malloc(sizeof(t_figure))))
		return (NULL);
	if (!(figure->code = (int *)malloc(sizeof(int) * 4)))
		return (NULL);
	figure->board_len = board_len;
	figure->next = NULL;
	figure->position = 0;
	ft_fg_addback(fhead, figure);
	return (*fhead);
}
