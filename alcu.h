/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alcu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddupart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 14:46:35 by ddupart           #+#    #+#             */
/*   Updated: 2015/12/20 22:34:18 by ddupart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ALCU_H_
# define _ALCU_H_
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <ctype.h>
# include <fcntl.h>
# include "libft.h"
# define DEBUG ft_putendl("DEBUG");

int		ft_save_line(char **board);
int		ft_save_match(char *board);
void	ft_display_board(char **board);
int		ft_count_lines(char *buf);
int		ft_count_lines_standard(char *buf);

char	**ft_read(char **argv);

char	**ft_read_standard_input(char **argv);

int		ft_play_first(char **board);
int		ft_play_second(char **board);

int		ft_win_or_die(char **board, int current_line, int total_match, int swap);
int		ft_computer_turn(char **board, int current_line, int total_match, int swap);
int		ft_begin_cheat_lame(char **board);

#endif
