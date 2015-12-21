/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_computer_turn.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddupart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 17:19:27 by ddupart           #+#    #+#             */
/*   Updated: 2015/12/21 22:54:06 by ddupart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

int		ft_win_line(int match)
{
	if (match % 4 == 0)
		return (3);
	if (match % 4 == 1)
		return (1);
	if (match % 4 == 2)
		return (1);
	if (match % 4 == 3)
		return (2);
	return (0);
}

int		ft_loose_line(int match)
{
	if (match % 4 == 0)
		return (3);
	if (match % 4 == 1)
		return (1);
	if (match % 4 == 2)
		return (2);
	if (match % 4 == 3)
		return (3);
	return (0);
}

int		ft_computer_turn(char **board, int current_line, int match, int line)
{
	int i;

	if (current_line == 1)
	{
		if (ft_save_match(board[0]) % 4 == 1
				&& line % 4 == 1)
			i = ft_loose_line(match);
		if (ft_save_match(board[0]) % 4 == 1
				&& line % 4 != 1)
			i = ft_win_line(match);
		if (ft_save_match(board[0]) % 4 != 1
				&& line % 4 == 1)
			i = ft_loose_line(match);
	}
	else
		i = ft_win_line(match);
	return (i);
}
