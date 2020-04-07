/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_remove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboggs <fboggs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 15:44:39 by fboggs            #+#    #+#             */
/*   Updated: 2019/08/05 15:44:39 by fboggs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		free_arr_points(int ***arr)
{
	int i;

	i = 0;
	while (i < 4)
	{
		free(*(*arr + i));
		*(*arr + i) = NULL;
		i++;
	}
	free(*arr);
	*arr = NULL;
}

void			free_t_tet(t_tet **tmp)
{
	t_tet *prev_lst;

	while (*tmp)
	{
		prev_lst = (*tmp)->prev;
		free_arr_points(&(*tmp)->points_y_x);
		(*tmp)->y_min = 0;
		(*tmp)->x_min = 0;
		(*tmp)->map_y = 0;
		(*tmp)->map_x = 0;
		(*tmp)->prev = NULL;
		(*tmp)->next = NULL;
		free(*tmp);
		*tmp = prev_lst;
	}
}

void			free_t_tet_head(t_tet **head)
{
	t_tet *next_lst;

	while (*head)
	{
		next_lst = (*head)->next;
		free_arr_points(&(*head)->points_y_x);
		(*head)->y_min = 0;
		(*head)->x_min = 0;
		(*head)->map_y = 0;
		(*head)->map_x = 0;
		(*head)->prev = NULL;
		(*head)->next = NULL;
		free(*head);
		*head = next_lst;
	}
}

void			free_t_field(char ***field, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(*(*field + i));
		*(*field + i) = NULL;
		i++;
	}
	free(*field);
	*field = NULL;
}

char			**remove_tetri(char **t_field, t_tet *tmp)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if ((t_field[(tmp)->points_y_x[i][0] + tmp->map_y]
			[(tmp)->points_y_x[i][1] + tmp->map_x]) != '.')
			t_field[(tmp)->points_y_x[i][0] + tmp->map_y]
			[(tmp)->points_y_x[i][1] + tmp->map_x] = '.';
		i++;
	}
	return (t_field);
}
