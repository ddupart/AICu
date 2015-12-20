/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_computer_turn.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddupart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 17:19:27 by ddupart           #+#    #+#             */
/*   Updated: 2015/12/20 21:28:19 by ddupart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

/*
 * Algo IA
 * Principe porteur pour le coup : toutes les parties sont gagnantes sauf celles comportant (4 * X) + 1 alums
 */

int	ft_win_or_die(char **board, int current_line, int total_match, int swap) //indique si la current_line est gagnante ou perdante et ajuste l'index swap en fonction
{
	if (ft_save_match(board[current_line]) % 4 == 1)
	{
		swap *= -1;
		return (swap);
	}
	else
		return (swap);
}

int	ft_begin_cheat_lame(char **board) //determine qui jouera le premier tour selon la disposition du board
{
	int		size;
	int		current;
	int		*tab;

	size = ft_save_line(board);
	if ((tab = (int*)malloc(sizeof(tab) * 2)) == NULL)
			return (-1);
	tab[0] = 0;							//index de victoire
	tab[1] = 0;							//index de defaite
	current = 0;
	while (current < size)
	{
		if (ft_save_match(board[current]) % 4 == 1)
			tab[1] += 1;
		else
			tab[0] += 1;
	}
		return (tab[1]);
}

static int	ft_win_line(char **board, int current_line, int total_match) //gagne la ligne
{
	if (total_match % 4 == 0)
		return (3);
	if (total_match % 4 == 3)
		return (2);
	if (total_match % 4 == 2)
		return (1);
	return (0);
}

static int	ft_loose_line(char **board, int current_line, int total_match, int swap) //perd la ligne
{
	if (swap == 1)
		return (ft_win_line(board, current_line, total_match));
	if (total_match % 4 == 1 || total_match == 3)
		return (3);
	if (total_match == 2)
		return (2);
	if (total_match == 1)
		return (1);
	return (0);
}

int			ft_computer_turn(char **board, int current_line, int total_match, int swap) //fonction d'appel
{
	int i;

	if (total_match % 4 != 1)
	{
		swap *= -1;
		i = ft_win_line(board, current_line, total_match);
	}
	else
		i = ft_loose_line(board, current_line, total_match, swap);
	return (i);
}
