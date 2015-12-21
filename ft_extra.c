/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddupart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 14:40:29 by ddupart           #+#    #+#             */
/*   Updated: 2015/12/21 22:49:54 by ddupart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

int		ft_save_line(char **board)
{
	int	i;

	i = 0;
	while (board[i])
		i++;
	return (i - 1);
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
	ft_putchar('\n');
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

char	**ft_check_and_get(int argc, char **argv)
{
	char	**board;

	if (argc > 2)
	{
		ft_putendl_fd("ERROR", 2);
		return (NULL);
	}
	if (argc == 2)
	{
		board = ft_read(argv);
		return (board);
	}
	else
	{
		board = ft_read_standard_input();
		return (board);
	}
}
