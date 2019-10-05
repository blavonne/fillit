/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures_code.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 20:35:15 by blavonne          #+#    #+#             */
/*   Updated: 2019/10/05 03:42:45 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int *get_code(const char *figure)
{
	int 	i;
	int 	j;
	int 	*code;

	if (!(code = (int *)malloc(sizeof(int) * 4)))
		return (NULL);
	i = 0;
	j = 0;
	while (i < 16)
	{
		if (figure[i] == '#')
			code[j++] = i;
		i++;
	}
	return (code);
}

int 	*recode(int *code, int len)
{
	int 	i;

	i = 1;
	while (i < 4)
	{
		if (code[i] >= 4 && code[i] < 8)
			code[i] = code[i] + (len - 4);
		else if (code[i] >= 8 && code[i] < 12)
			code[i] = code[i] + (len - 4) * 2;
		else if (code[i] >= 12 && code[i] < 16)
			code[i] = code[i] + (len - 4) * 3;
		i++;
	}
	return (code);
}

int	*move_up_left(int *code)
{
	if ((code[1] == code[0] + 1 && code[2] == code[0] + 3)\
	|| code[1] == code[0] + 3)
		while (code[0] != 1)
		{
			code[0]--;
			code[1]--;
			code[2]--;
			code[3]--;
		}
	else
		while (code[0] != 0)
		{
			code[0]--;
			code[1]--;
			code[2]--;
			code[3]--;
		}
	return (code);
}

int		set_code(t_figure **head, char *figures, int board_len)
{
	int			*code;
	t_figure	*tmp;
	char 		letter;

	letter = 'A';
	tmp = *head;
	while (*figures)
	{
		if (!(code = get_code(figures)))
			return (0);
		code = move_up_left(code);
		if (board_len != 4)
			code = recode(code, board_len);
		tmp->code = ft_memcpy(tmp->code, code, sizeof(int) * 4);
		free(code);
		tmp->letter = letter++;
		tmp = tmp->next;
		figures = figures + 16;
	}
	return (1);
}

void	display_code(t_figure *head)
{
	int 	i;
	int 	len;

	len = head->board_len;
	printf("\n");
	while (head)
	{
		i = 0;
		printf("Figure %c\n", head->letter);
		while (i < 4)
		{
			printf("%i ", head->code[i]);
			i++;
		}
		printf("\n");
		head = head->next;
	}
	printf("BOARD LEN %d\n", len);
}

int 	count_figures(char *figures)
{
	return ((int)ft_strlen(figures) / 16);
}