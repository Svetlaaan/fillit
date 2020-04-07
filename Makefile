# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fboggs <fboggs@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/05 15:11:00 by fboggs            #+#    #+#              #
#    Updated: 2019/08/07 11:37:37 by fboggs           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

NAME = fillit

LIB_DIR = libft

SRC = main.c is_file_valid.c save_x_y.c map.c free_and_remove.c make_new.c

OBJ = $(SRC:.c=.o)

LIBA = libft.a

R_LIBA = make -C $(LIB_DIR)

CFLAGS = -Wall -Wextra -Werror

LFLAGS = -L $(LIB_DIR) -lft

all: $(NAME)

$(LIBA):
			$(R_LIBA)

%.o:%.c
			gcc -c $(CFLAGS) -I. $<

$(NAME): $(LIBA) $(OBJ)
			@gcc $(CFLAGS) $(LFLAGS) -I. -o $@ $(OBJ)

clean:
			rm -f $(OBJ)
			make -C libft clean

fclean: clean
			rm -f $(NAME)
			make -C libft fclean

re: fclean all
