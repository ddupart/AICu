/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 11:36:24 by vlistrat          #+#    #+#             */
/*   Updated: 2015/12/21 21:38:13 by ddupart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

static void		ft_fill_board(char **board, int i, int count, int max)
{
	int		fill;
	int		j;

	j = 0;
	fill = (max - i) / 2;
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

static char		**ft_board(char *buf, int lines, int max)
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
		if (ft_atoi(buf + j) < 1 || ft_atoi(buf + j) > 10000 || buf[i] != '\n'
				|| (!(ft_isdigit((int)buf[i + 1])) && buf[i + 1] != '\0'))
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
		if (ft_atoi(buf + j) < 1 || ft_atoi(buf + j) > 10000 || buf[i] != '\n'
				|| (!(ft_isdigit((int)buf[i + 1])) && buf[i + 1] != '\0'))
			return (0);
		if (ft_atoi(buf + j) > max)
			max = ft_atoi(buf + j);
		i++;
		j = i;
	}
	return (max);
}

char			**ft_read(char **argv)
{
	int		fd;
	int		ret;
	char	*buf;
	char	**board;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (NULL);
	buf = (char*)malloc(sizeof(*buf) * 10000);
	if (buf == NULL)
		return (NULL);
	ret = read(fd, buf, 10000);
	buf[ret] = '\0';
	close(fd);
	ret = ft_count_lines(buf);
	board = ft_board(buf, ret, ft_get_max(buf));
	free(buf);
	return (board);
}
