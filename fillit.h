#ifndef FILLIT_FILLIT_H
#define FILLIT_FILLIT_H

#define ERROR -1
#define BUFF_SIZE 546
# include <libft/libft.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>


typedef struct		s_tetrimino
{
	int				**points_x_y;
	struct s_list	*next;
	struct s_list	*prev;
}					t_tet;


int 				is_file_valid(char *argv, int *p_sum_fig);
int					is_figure_valid(const char *buf, int sum_tet);
int 				save_x_y(t_tet *head, char *argv);

#endif
