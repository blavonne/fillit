/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fugures_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 17:44:25 by blavonne          #+#    #+#             */
/*   Updated: 2019/10/01 16:38:31 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"

void		ft_fg_addback(t_figure **head, t_figure *new)
{
	t_figure	*tmp;
	t_figure	*phead;

	tmp = *head;
	phead = tmp;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	*head = phead;
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

t_figure	*create_fg(t_figure **head, int board_len)
{
	t_figure	*figure;

	if (!*head)
	{
		if (!(figure = (t_figure *)malloc(sizeof(t_figure))))
			return (NULL);
		if (!(figure->code = (int *)malloc(sizeof(int) * 4)))
			return (NULL);
		figure->board_len = board_len;
		figure->next = NULL;
		*head = figure;
		return (*head);
	}
	if (!(figure = (t_figure *)malloc(sizeof(t_figure))))
		return (NULL);
	if (!(figure->code = (int *)malloc(sizeof(int) * 4)))
		return (NULL);
	figure->board_len = board_len;
	figure->next = NULL;
	ft_fg_addback(head, figure);
	return (*head);
}
