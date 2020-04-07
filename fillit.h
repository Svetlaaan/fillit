/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboggs <fboggs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 15:57:03 by fboggs            #+#    #+#             */
/*   Updated: 2019/08/05 16:34:30 by fboggs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define ERROR -1
# define BUFF_SIZE 546
# include <libft/libft.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct			s_tetrimino
{
	int					**points_y_x;
	int					map_y;
	int					map_x;
	int					y_min;
	int					x_min;
	char				letter;
	struct s_tetrimino	*next;
	struct s_tetrimino	*prev;
}						t_tet;

int						is_file_valid(char *buffer, int read_chrs,
		int *sum_tetriminos);
t_tet					*save_x_y(char *buf, int sum_tetriminos, t_tet **head);
void					free_t_tet(t_tet **tmp);
void					free_t_tet_head(t_tet **head);
void					free_t_field(char ***field, int size);
int						map(t_tet *head, int sum_tet);
char					**remove_tetri(char **t_field, t_tet *tmp);
void					print_field(char **field, int size);
t_tet					*new_tet_points(char letter);
char					**new_field(char **field, int size);

#endif
