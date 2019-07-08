# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fboggs <fboggs@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/25 16:00:18 by fboggs            #+#    #+#              #
#    Updated: 2019/07/08 16:42:13 by fboggs           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIB_DIR = libft

SRC = main.c

OBJ = $(SRC: .c = .o)

LIBA_SRC = libft/ft_atoi.c \
		libft/ft_bzero.c \
		libft/ft_cntwrds.c \
		libft/ft_deltwodimarray.c \
		libft/ft_isalnum.c \
		libft/ft_isalpha.c \
		libft/ft_isascii.c \
		libft/ft_isdigit.c \
		libft/ft_isprint.c \
		libft/ft_iswhitespace.c \
		libft/ft_itoa.c \
		libft/ft_lstadd.c \
		libft/ft_lstdel.c \
		libft/ft_lstdelone.c \
		libft/ft_lstiter.c \
		libft/ft_lstmap.c \
		libft/ft_lstnew.c \
		libft/ft_memalloc.c \
		libft/ft_memccpy.c \
		libft/ft_memchr.c \
		libft/ft_memcmp.c \
		libft/ft_memcpy.c \
		libft/ft_memdel.c \
		libft/ft_memmove.c \
		libft/ft_memset.c \
		libft/ft_putchar_fd.c \
		libft/ft_putchar.c \
		libft/ft_putendl.c \
		libft/ft_putendl_fd.c \
		libft/ft_putnbr_fd.c \
		libft/ft_putnbr.c \
		libft/ft_putstr_fd.c \
		libft/ft_putstr.c \
			libft/ft_strcat.c \
		libft/ft_strchr.c \
		libft/ft_strclr.c \
		libft/ft_strcmp.c \
		libft/ft_strcpy.c \
		libft/ft_strdel.c \
		libft/ft_strdup.c \
		libft/ft_strequ.c \
		libft/ft_striter.c \
		libft/ft_striteri.c \
		libft/ft_strjoin.c \
		libft/ft_strlcat.c \
		libft/ft_strlen.c \
		libft/ft_strmap.c \
		libft/ft_strmapi.c \
		libft/ft_strncat.c \
		libft/ft_strncmp.c \
		libft/ft_strncpy.c \
		libft/ft_strnequ.c \
		libft/ft_strnew.c \
		libft/ft_strnstr.c \
		libft/ft_strrchr.c \
		libft/ft_strsplit.c \
		libft/ft_strstr.c \
		libft/ft_strsub.c \
		libft/ft_strtrim.c \
		libft/ft_tolower.c \
		libft/ft_toupper.c

LIBA_OBJ = $(LIBA_SRC: .c = .o)

LIBA = libft.a

CFLAGS = -Wall -Wextra -Werror

LFLAGS = -L. -lft

.PHONY : all clean fclean re

all: $(NAME)

$(NAME): $(LIBA)
			gcc $(CFLAGS) $(LFLAGS) -I. $(SRC) -o $@


$(LIBA):
			gcc $(CFLAGS) -c $(LIBA_SRC)
			ar rc $@ $(LIBA_OBJ)

clean:
			rm -f *.o $(LIBA)

fclean: clean
			rm -f $(NAME)

re: fclean all
