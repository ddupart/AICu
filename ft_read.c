/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 11:36:24 by vlistrat          #+#    #+#             */
/*   Updated: 2015/12/20 18:28:41 by ddupart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

static void		ft_fill_board(char **board, int i, int count)
{
	int		fill;

	fill = 0;
	while (fill < i)
	{
		board[count][fill] = '|';
		fill++;
	}
	board[count][fill] = '\0';
}

static char		**ft_board(char *buf, int lines)
{
	int		i;
	int		j;
	int		count;
	char	**board;

	i = 0;
	count = 0;
	j = 0;
	if ((board = (char**)malloc(sizeof(*board) * lines + 1)) == NULL)
		return (NULL);
	while (/*buf[i] &&*/ count < lines)
	{
		while (ft_isdigit((int)buf[i]))
			i++;
		if (ft_atoi(buf + j) < 1 || ft_atoi(buf + j) > 10000 || buf[i] != '\n')
			return (NULL);
		if ((board[count] = (char*)malloc(sizeof(*board) * ft_atoi(buf + j) + 1)) == NULL)
			return (NULL);
		ft_fill_board(board, ft_atoi(buf + j), count);
		count++;
		i++;
		j = i;
	}
	board[count] = NULL;
	return (board);
}

char	**ft_read(char **argv)
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
	board = ft_board(buf, ret);
	return (board);
}
