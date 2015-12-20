/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddupart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 11:28:43 by ddupart           #+#    #+#             */
/*   Updated: 2015/12/20 22:10:03 by ddupart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	char	**board;
	int		winner;

	if (argc > 2)
	{
		ft_putendl_fd("ERROR", 2);
		return (0);
	}
//	if (argc == 2)
//		board = ft_read(argv);	//lecture sur fichier ou entree standard si pas d'argument
//	else
		board = ft_read_standard_input(argv);
/*	if (ft_begin_cheat_lame(board) % 2 == -1)
 *	{
 		ft_putendl_fd("ERROR", 2);
		return (0);
		}
	else if (ft_begin_cheat_lame(board) % 2 == 0)
		winner = ft_play_first(board);
	else
		winner = ft_play_second(board);
	if (winner == 0)
	{
		ft_putendl("Computer owns you");
		return (0);
	}
	else
	{
		ft_putendl("Garry Kasparov is nothing to you :)");
		return (0);
	}*/
	ft_display_board(board);
	return (0);
}
