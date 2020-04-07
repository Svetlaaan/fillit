/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboggs <fboggs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 15:44:25 by fboggs            #+#    #+#             */
/*   Updated: 2019/08/07 11:16:45 by fboggs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		move_tet(t_tet *tmp, int *i, int a)
{
	if (a == 1)
	{
		tmp->map_x += 1;
		*i = 0;
	}
	else if (a == 2)
	{
		tmp->map_x = 0;
		*i = 0;
		tmp->map_y += 1;
	}
	else if (a == 3)
	{
		tmp->map_y = 0;
		tmp->map_x = 0;
	}
}

static int		is_tet_fit(char **field, t_tet *tmp, int size)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if ((tmp->points_y_x[i][0] + tmp->map_y) < 0 ||
			(tmp->points_y_x[i][1] + tmp->map_x) < 0)
			move_tet(tmp, &i, 1);
		else if ((tmp->points_y_x[i][0] + tmp->map_y) < size &&
		(tmp->points_y_x[i][1] + tmp->map_x) < size)
		{
			if (field[tmp->points_y_x[i][0] + tmp->map_y]
			[tmp->points_y_x[i][1] + tmp->map_x] == '.')
				i++;
			else if ((tmp->points_y_x[i][1] + tmp->map_x) < size - 1)
				move_tet(tmp, &i, 1);
			else
				move_tet(tmp, &i, 2);
		}
		else
			return (0);
	}
	return (1);
}

static void		place_tet(t_tet *tmp, char ***t_field)
{
	int i;

	i = 0;
	while (i < 4)
	{
		*(*(*t_field + tmp->points_y_x[i][0] + tmp->map_y) +
			(tmp->points_y_x[i][1] + tmp->map_x)) = tmp->letter;
		i++;
	}
}

static char		**algoritm(char **t_field, t_tet *tmp, int size)
{
	char	**map;

	if (tmp == NULL)
		return (t_field);
	while (tmp->map_y < size)
	{
		tmp->map_x = 0;
		while (tmp->map_x < size)
		{
			if (is_tet_fit(t_field, tmp, size))
			{
				place_tet(tmp, &t_field);
				if (!(map = algoritm(t_field, tmp->next, size)))
					t_field = remove_tetri(t_field, tmp);
				if (map)
					return (map);
			}
			tmp->map_x += 1;
		}
		tmp->map_y += 1;
	}
	move_tet(tmp, 0, 3);
	if (!tmp->prev)
		free_t_field(&t_field, size);
	return (NULL);
}

int				map(t_tet *head, int sum_tet)
{
	char	**t_field;
	int		min_size;
	int		size;

	size = 2;
	t_field = NULL;
	min_size = sum_tet * 4;
	while (min_size > size * size)
		size++;
	if (!(t_field = new_field(t_field, size)))
		return (0);
	while (!(t_field = algoritm(t_field, head, size)))
	{
		size++;
		if (t_field)
			free_t_field(&t_field, size);
		if (!(t_field = new_field(t_field, size)))
		{
			free_t_field(&t_field, size);
			return (0);
		}
	}
	print_field(t_field, size);
	free_t_field(&t_field, size);
	return (1);
}
