/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_standard_input.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddupart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 16:14:59 by ddupart           #+#    #+#             */
/*   Updated: 2015/12/21 23:05:13 by ddupart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

static int		ft_get_lines(char *buf)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (buf[i])
	{
		if (ft_isdigit((int)buf[i]))
		{
			count++;
			while (ft_isdigit((int)buf[i]))
				i++;
		}
		i++;
	}
	return (count);
}

static void		ft_fill_board(char **board, int i, int count, int max)
{
	int		fill;
	int		j;

	fill = (max - i) / 2;
	j = 0;
	while (j < fill)
	{
		board[count][j] = ' ';
		j++;
	}
	j = 0;
	while (j < i)
	{
		board[count][fill] = '|';
		fill++;
		j++;
	}
	while (fill < max)
	{
		board[count][fill] = ' ';
		fill++;
	}
	board[count][max] = '\0';
}

static char		**ft_board_standard(char *buf, int lines, int max)
{
	int		i;
	int		j;
	int		count;
	char	**board;

	i = 0;
	count = -1;
	j = 0;
	if ((board = (char**)malloc(sizeof(*board) * lines + 1)) == NULL)
		return (NULL);
	while (++count < lines)
	{
		while (ft_isdigit((int)buf[i]))
			i++;
		if (ft_atoi(buf + j) < 1 || ft_atoi(buf + j) > 10000 || (buf[i] != ' '
					&& buf[i] != '\0' && buf[i] != '\n'))
			return (NULL);
		if ((board[count] = (char*)malloc(sizeof(*board) * max + 1)) == NULL)
			return (NULL);
		ft_fill_board(board, ft_atoi(buf + j), count, max);
		i++;
		j = i;
	}
	board[count] = NULL;
	return (board);
}

static int		ft_get_max(char *buf)
{
	int		i;
	int		j;
	int		max;

	i = 0;
	j = 0;
	max = 0;
	while (buf[i])
	{
		while (ft_isdigit((int)buf[i]))
			i++;
		if (ft_atoi(buf + j) < 1 || ft_atoi(buf + j) > 10000 || (buf[i] != ' '
					&& buf[i] != '\n') || (!(ft_isdigit((int)buf[i + 1]))
						&& buf[i + 1] != '\0'))
			return (0);
		if (ft_atoi(buf + j) > max)
			max = ft_atoi(buf + j);
		i++;
		j = i;
	}
	return (max);
}

char			**ft_read_standard_input(void)
{
	int		ret;
	char	*buf;
	char	**board;

	ret = 0;
	buf = (char*)malloc(sizeof(*buf) * 10000);
	if (buf == NULL)
		return (NULL);
	ft_putendl("Choose the size of the battlefield !");
	while (buf[ret - 1] != 10 && buf[ret] != 13)
		ret = read(0, buf, 10000);
	buf[ret] = '\0';
	ret = ft_get_lines(buf);
	if (ft_get_max(buf) == 0)
		return (NULL);
	board = ft_board_standard(buf, ret, ft_get_max(buf));
	return (board);
}
