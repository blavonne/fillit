/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures_code.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <blavonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 20:35:15 by blavonne          #+#    #+#             */
/*   Updated: 2019/10/21 13:18:54 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static int	*get_code(const char *figure)
{
	int		i;
	int		j;
	int		*code;

	if (!(code = (int *)malloc(sizeof(int) * 4)))
		return (NULL);
	i = 0;
	j = 0;
	while (i < 16 && j < 4)
	{
		if (figure[i] == '#')
			code[j++] = i;
		i++;
	}
	return (code);
}

static int	*recode(int *code, int len)
{
	int		i;

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

static int	*move_up_left(int *code)
{
	while ((code[0] / 4) && (code[1] / 4) && (code[2] / 4) && (code[3] / 4))
	{
		code[0] -= 4;
		code[1] -= 4;
		code[2] -= 4;
		code[3] -= 4;
	}
	while ((code[0] % 4) && (code[1] % 4) && (code[2] % 4) && (code[3] % 4))
	{
		code[0]--;
		code[1]--;
		code[2]--;
		code[3]--;
	}
	return (code);
}

static void	set_width(t_figure **tmp, int *code)
{
	int		i;
	int		width;

	i = 0;
	width = 0;
	while (i < 4)
	{
		if ((code[i] % 4) > width)
			width = code[i] % 4;
		i++;
	}
	width++;
	(*tmp)->width = width;
}

int			set_code(t_figure **head, char *figures, int board_len)
{
	int			*code;
	t_figure	*tmp;
	char		letter;

	letter = 'A';
	tmp = *head;
	while (*figures)
	{
		if (!(code = get_code(figures)))
			return (0);
		code = move_up_left(code);
		set_width(&tmp, code);
		if (board_len != 4)
			code = recode(code, board_len);
		tmp->code = ft_memcpy(tmp->code, code, sizeof(int) * 4);
		tmp->letter = letter++;
		free(code);
		tmp = tmp->next;
		figures = figures + 16;
	}
	return (1);
}
