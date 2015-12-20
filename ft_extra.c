/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddupart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 14:40:29 by ddupart           #+#    #+#             */
/*   Updated: 2015/12/20 17:06:34 by ddupart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

int		ft_save_line(char **board)
{
	int	i;

	i = 0;
	while (board[i])
		i++;
	return (i);
}
int		ft_save_match(char *board)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (board[i])
	{
		if (board[i] == '|')
			n++;
		i++;
	}
	return (n);
}

void	ft_display_board(char **board)
{
	int	i;

	i = 0;
	while (board[i])
	{
		ft_putendl(board[i]);
		i++;
	}
}

int		ft_count_lines(char *buf)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

int		ft_count_lines_standard(char *buf)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (buf[i])
	{
		if (buf[i] == ' ')
			count++;
		i++;
	}
	if (buf[i - 1] == ' ')
		count--;
	return (count);
}
