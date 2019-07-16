# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fboggs <fboggs@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/25 16:00:18 by fboggs            #+#    #+#              #
#    Updated: 2019/07/16 14:10:44 by fboggs           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIB_DIR = libft

SRC = main.c

OBJ = $(SRC:.c=.o)

LIBA = libft.a

R_LIBA = make -C $(LIB_DIR)

CFLAGS = -Wall -Wextra -Werror

LFLAGS = -L $(LIB_DIR) -lft

.PHONY : all clean fclean re

all: $(NAME)

$(NAME): $(LIBA) $(OBJ)
			gcc $(CFLAGS) $(LFLAGS) -I. -o $@ $(OBJ)

%o:%c
			gcc $(CFLAGS) -I. -c $<

$(LIBA):
			$(R_LIBA)

clean:
			rm -f $(OBJ)
			make -C libft clean

fclean: clean
			rm -f $(NAME)
			make -C libft fclean

re: fclean all
