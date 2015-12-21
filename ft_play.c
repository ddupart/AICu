/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddupart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 16:24:05 by ddupart           #+#    #+#             */
/*   Updated: 2015/12/21 22:52:13 by ddupart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

static int	ft_player_turn(int total_match)
{
	int		valid;
	int		ret;
	char	*s;

	valid = 0;
	ret = 10;
	while (valid != 1)
	{
		s = (char*)malloc(sizeof(*s) * 100 + 1);
		while (s[ret - 1] != 10 && s[ret] != 13)
		{
			ft_putendl("How many matches do you want to drag away?");
			ret = read(0, s, 100);
			s[ret] = '\0';
		}
		if (total_match - ft_atoi(s) < 0 || ft_atoi(s) < 1 || ft_atoi(s) > 3)
		{
			ft_putendl("The move you want to do is not allowed at this time");
			valid = -1;
		}
		else
			valid = 1;
	}
	return (ft_atoi(s));
}

static int	ft_rows(char **board, int total_match, int match, int current_line)
{
	int line;

	while (--current_line >= 0)
	{
		total_match = ft_save_match(board[current_line]);
		line = total_match;
		while (total_match != 0)
		{
			ft_putendl("Computer plays : ");
			match = ft_computer_turn(board, current_line, total_match, line);
			ft_update_board(board, current_line, match);
			if ((total_match -= match) == 0 && current_line > 0)
			{
				current_line--;
				total_match = ft_save_match(board[current_line]);
			}
			if (total_match == 0 && current_line == 0)
				return (1);
			match = ft_player_turn(total_match);
			ft_update_board(board, current_line, match);
			if ((total_match -= match) == 0 && current_line == 0)
				return (0);
		}
	}
	return (1);
}

void		ft_play(char **board)
{
	int		current_line;

	current_line = ft_save_line(board) + 1;
	if (ft_rows(board, 0, 0, current_line) == 1)
		ft_putendl("You got me :(");
	else
		ft_putendl("Rampage computer ;)");
}
