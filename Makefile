# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddupart <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/20 17:36:22 by ddupart           #+#    #+#              #
#    Updated: 2015/12/21 22:57:20 by ddupart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = alum1

SRC = main.c \
	  ft_read.c \
	  ft_read_standard_input.c \
	  ft_play.c \
	  ft_computer_turn.c \
	  ft_extra.c \
	  ft_update_board.c

OBJ = $(SRC:.c=.o)

LIB = -lft

LIBDIR = libft

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -L. $(LIB)

$(OBJ): $(LIB)
	gcc -c $(SRC) -Wall -Werror -Wextra

$(LIB):
	@(cd $(LIBDIR) && $(MAKE) && cp $(LIBDIR).a $(LIBDIR).h ../)

clean: cleanlib
	/bin/rm -f $(OBJ) $(LIBDIR).a $(LIBDIR).h

cleanlib:
	@(cd $(LIBDIR) && $(MAKE) clean)

fclean: clean fcleanlib
	/bin/rm -f $(NAME) $(LIBDIR).a $(LIBDIR).h

fcleanlib:
	@(cd $(LIBDIR) && $(MAKE) fclean)

re: fclean all
