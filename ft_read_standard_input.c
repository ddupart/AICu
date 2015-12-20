/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_standard_input.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddupart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 16:14:59 by ddupart           #+#    #+#             */
/*   Updated: 2015/12/20 22:38:12 by ddupart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

/*
 * Read sur standard input si pas d'arguments passe, stade ebauche pour le moment, a retravailler avant de rendre
 */
static int		ft_get_lines(char *buf)
{
	int i;
	int count;

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

static void     ft_fill_board(char **board, int i, int count)
{
	int     fill;

	fill = 0;
	while (fill < i)
	{
		board[count][fill] = '|';
		fill++;
	}
	board[count][fill] = '\0';
}

static char     **ft_board_standard(char *buf, int lines)
{
	int     i;
	int     j;
	int     count;
	char    **board;

	i = 0;
	count = 0;
	j = 0;
	if ((board = (char**)malloc(sizeof(*board) * lines + 1)) == NULL)
		return (NULL);
	while (count < lines)
	{
		while (ft_isdigit((int)buf[i]))
			i++;
		DEBUG
		if (ft_atoi(buf + j) < 1 || ft_atoi(buf + j) > 10000 || (buf[i] != ' ' && buf[i] != '\n'))
			return (NULL);
	DEBUG
		if ((board[count] = (char*)malloc(sizeof(*board) * ft_atoi(buf + j) + 1)) == NULL)
			return (NULL);
		ft_fill_board(board, ft_atoi(buf + j), count);
		ft_putnbr(count);
		ft_putchar('\n');
		count++;
		i++;
		j = i;
	}
	board[count] = NULL;
	return (board);
}

char    **ft_read_standard_input(char **argv)
{
	int     i;
	int     ret;
	char    *buf;
	char    *dst;
	char **board;
	int		j;

//	ret = 10;
	j = 0;
	buf = (char*)malloc(sizeof(*buf) * 10000);
	if (buf == NULL)
		return (NULL);
//	while (buf[ret - 1] != 10 && buf[ret] != 13)
	while (ft_strstr(buf, "\n\n") == 0)
	{
		ret = read(0, &buf[j], 1);
		j++;
	}
	buf[j] = '\0';
	ft_putstr("STRLEN : ");
	ft_putnbr((int)ft_strlen(buf));
	ft_putchar('\n');	
	ft_putendl(buf);
	ret = ft_get_lines(buf);
	ft_putstr("LIGNES : ");
	ft_putnbr(ret);
	ft_putchar('\n');
	board = ft_board_standard(buf, ret);
	return (board);
}
