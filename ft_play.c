/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddupart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 16:24:05 by ddupart           #+#    #+#             */
/*   Updated: 2015/12/20 21:23:49 by ddupart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

/*
 * Besoin d'une bonne mise a la norme
 */

static void	ft_update_board(char **board, int current_line, int current_match, int len)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (board[current_line][i] == ' ')
		i++;
	board[current_line][i] = ' ';
	while (board[current_line][len] == ' ')
	{
		len--;
		j++;
	}
	board[current_line][len] = ' ';
	if (current_match == 2)
	{
		board[current_line][i] = ' ';
		board[current_line][len] = ' ';
	}
	if (current_match == 1 && i > j)
		board[current_line][len] = ' ';
	else	
		board[current_line][i] = ' ';
	if (current_match == 3 && i > j)
	{
		board[current_line][i] = ' ';
		board[current_line][len] = ' ';
		board[current_line][len - 1] = ' ';
	}
	else
	{
		board[current_line][i] = ' ';
		board[current_line][len] = ' ';
		board[current_line][i + 1] = ' ';
	}
}

static int	ft_player_turn(char *board, int total_match)
{
	int 	i;
	int		valid;
	int		ret;
	char	*dst;

	valid = 0;
	dst = (char*)malloc(sizeof(*dst) * 10 + 1);
	while (valid != 1)
	{
		if (valid == -1)
			ft_putendl("The move you want to do is not allowed at this time");
		while (dst[ret - 1] != 10 && dst[ret] != 13)
		{
			ft_putendl("How many matches do you want to drag away?");
			ret = read(0, dst, 10);
			dst[ret] = '\0';
		}
		if (ft_atoi(dst) - total_match < 0 || ft_atoi(dst) < 1 || ft_atoi(dst) > 3)
			valid = -1;
		else
			valid = 1;
	}
	return (ft_atoi(dst));
}

int		ft_play_first(char **board)
{
	int		current_line;
	int		total_match;
	int		actual_match;
	int 	current_len;
	int		swap;

	swap = 1;
	current_line = ft_save_line(board);
	while (current_line >= 0)
	{
		swap = ft_win_or_die(board, current_line, total_match, swap);
		total_match = ft_save_match(board[current_line]);
		current_len = (int)ft_strlen(board[current_line]);
		while (total_match != 0)
		{
			actual_match = ft_computer_turn(board, current_line, total_match, swap);
			ft_update_board(board, current_line, actual_match, current_len);
			if ((total_match -= actual_match) == 0)
				return (1);
			actual_match = ft_player_turn(board[current_line], total_match);
			ft_update_board(board, current_line, actual_match, current_len);
			if ((total_match -= actual_match) == 0)
				return (0);
		}
		current_line--;
	}
	return (-1);
}

int		ft_play_second(char **board)
{
	int		current_line;
	int		total_match;
	int		actual_match;
	int 	current_len;
	int		swap;

	swap = 1;
	current_line = ft_save_line(board);
	while (current_line >= 0)
	{
		swap = ft_win_or_die(board, current_line, total_match, swap);
		total_match = ft_save_match(board[current_line]);
		current_len = (int)ft_strlen(board[current_line]);
		while (total_match != 0)
		{
			actual_match = ft_player_turn(board[current_line], total_match);
			ft_update_board(board, current_line, actual_match, current_len);
			if ((total_match -= actual_match) == 0)
				return (1);
			actual_match = ft_computer_turn(board, current_line, total_match, swap);
			ft_update_board(board, current_line, actual_match, current_len);
			if ((total_match -= actual_match) == 0)
				return (0);
		}
		current_line--;
	}
	return (-1);
}
