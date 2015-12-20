# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddupart <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/20 17:36:22 by ddupart           #+#    #+#              #
#    Updated: 2015/12/20 18:24:57 by ddupart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = alum1

SRC = main.c \
	  ft_read.c \
	  ft_read_standard_input.c \
	  ft_play.c \
	  ft_computer_turn.c \
	  ft_extra.c

OBJ = $(SRC:.c=.o)

LIB = lft

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -L. -$(LIB)

$(OBJ):
	gcc -c $(SRC)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
