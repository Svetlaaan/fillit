/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboggs <fboggs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 15:44:32 by fboggs            #+#    #+#             */
/*   Updated: 2019/08/05 15:44:32 by fboggs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		**new_arr_points(void)
{
	int		**new;
	int		i;

	i = 0;
	if (!(new = (int**)malloc(4 * sizeof(int*))))
		return (NULL);
	while (i < 4)
	{
		new[i] = (int*)malloc(2 * sizeof(int));
		i++;
	}
	return (new);
}

t_tet			*new_tet_points(char letter)
{
	t_tet *new;

	if (!(new = (t_tet*)malloc(sizeof(t_tet))))
		return (NULL);
	new->points_y_x = new_arr_points();
	new->map_y = 0;
	new->map_x = 0;
	new->y_min = -1;
	new->x_min = -1;
	new->next = NULL;
	new->prev = NULL;
	new->letter = letter;
	return (new);
}

static void		free_if_not(int y, char ***field)
{
	while (y >= 0)
	{
		free(field[y]);
		y--;
		field[y] = NULL;
	}
	free(field);
	field = NULL;
}

char			**new_field(char **field, int size)
{
	int		x;
	int		y;

	y = 0;
	if (!(field = (char **)malloc(sizeof(char *) * size)))
		return (NULL);
	while (y < size)
	{
		if (!(field[y] = ft_memalloc(size + 1)))
		{
			free_if_not(y, &field);
			return (NULL);
		}
		x = 0;
		while (x < size)
			field[y][x++] = '.';
		field[y][x] = '\0';
		y++;
	}
	return (field);
}
