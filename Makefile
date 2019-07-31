
.PHONY : all clean fclean re

NAME = fillit

LIB_DIR = libft

SRC = main.c is_file_valid.c save_x_y.c total.c free_t_tet.c

OBJ = $(SRC:.c=.o)

LIBA = libft.a

R_LIBA = make -C $(LIB_DIR)

CFLAGS = -Wall -Wextra -Werror

LFLAGS = -L $(LIB_DIR) -lft

all: $(NAME)

$(OBJ): %o: %c
			gcc -c $(CFLAGS) -I. $<

$(LIBA):
			$(R_LIBA)

$(NAME): $(LIBA) $(OBJ)
			@gcc $(CFLAGS) $(LFLAGS) -I. -o $@ $(OBJ)

clean:
			rm -f $(OBJ)
			make -C libft clean

fclean: clean
			rm -f $(NAME)
			make -C libft fclean

re: fclean all
