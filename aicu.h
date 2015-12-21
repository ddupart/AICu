/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alcu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddupart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 14:46:35 by ddupart           #+#    #+#             */
/*   Updated: 2015/12/21 22:54:29 by ddupart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AICU_H
# define AICU_H
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <fcntl.h>
# include "libft.h"

int		ft_save_line(char **board);
int		ft_save_match(char *board);
void	ft_display_board(char **board);
int		ft_count_lines(char *buf);
char	**ft_check_and_get(int argc, char **argv);

char	**ft_read(char **argv);

char	**ft_read_standard_input(void);

void	ft_play(char **board);

int		ft_computer_turn(char **board, int current_line, int match, int line);
int		ft_win_line(int total_match);
int		ft_loose_line(int total_match);

void	ft_update_board(char **board, int line, int match);

#endif
