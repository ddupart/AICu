/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_board.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddupart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 13:39:33 by ddupart           #+#    #+#             */
/*   Updated: 2015/12/21 21:39:55 by ddupart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

static void	ft_one_match(char *board, int n)
{
	board[n] = ' ';
}

static void	ft_two_matches(char *board, int i, int len)
{
	board[i] = ' ';
	board[len] = ' ';
}

static void	ft_three_matches(char *board, int i, int len, int j)
{
	if (i >= j)
	{
		ft_one_match(board, len);
		len--;
	}
	else
	{
		ft_one_match(board, i);
		i++;
	}
	ft_two_matches(board, i, len);
}

void		ft_update_board(char **board, int line, int match)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = (int)ft_strlen(board[line]) - 1;
	while (board[line][i] == ' ')
		i++;
	while (board[line][len] == ' ')
	{
		len--;
		j++;
	}
	if (match == 2)
		ft_two_matches(board[line], i, len);
	if (match == 1 && i >= j)
		ft_one_match(board[line], len);
	else
		ft_one_match(board[line], i);
	if (match == 3)
		ft_three_matches(board[line], i, len, j);
	ft_display_board(board);
}
