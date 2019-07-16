#ifndef FILLIT_FILLIT_H
#define FILLIT_FILLIT_H

#define ERROR -1
#define BUFF_SIZE 546
# include <libft/libft.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>


typedef struct		tetrimino
{
	int				**points_y_x;
	int             y_min;
	int             x_min;
	struct tetrimino	*next;
	struct tetrimino	*prev;
}					t_tet;


int 				is_file_valid(char *argv, int *sum_tetriminos);
int					is_figure_valid(char *buf);
void * save_x_y(char *argv, char *buf, int sum_tetriminos, t_tet *head);
void    			total(t_tet *buffer);

#endif
