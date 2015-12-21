/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddupart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 11:28:43 by ddupart           #+#    #+#             */
/*   Updated: 2015/12/21 22:50:29 by ddupart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

int	main(int argc, char **argv)
{
	char	**board;

	board = ft_check_and_get(argc, argv);
	if (board == NULL)
	{
		ft_putendl_fd("ERROR", 2);
		return (0);
	}
	ft_putendl("Game begins, here is the initial board");
	ft_display_board(board);
	ft_play(board);
	return (0);
}
