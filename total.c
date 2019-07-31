#include "fillit.h"

static char		**new_field(char **field, int size)
{
	int		x;
	int		y;

	y = 0;
	field = (char **)malloc(sizeof(char *) * size + 1);
	if (!field)
		return (NULL);
	while (y < size)
	{
		if (!(field[y] = (char *)malloc(sizeof(char) * size + 1)))
			return (NULL);
		x = 0;
		while (x < size)
			field[y][x++] = '.';
		field[y][x] = '\0';
		y++;
	}
	field[y] = 0;
	return (field);
}

static void		move_tetri(t_tet *tmp, int *i, int a)
{
	if (a == 1)
	{
		tmp->x += 1;
		*i = 0;
	}
	else if (a == 2)
	{
		tmp->x = 0;
		*i = 0;
		tmp->y += 1;
	}
}

static int		is_tet_fit(char **field, t_tet *tmp, int size)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if ((tmp->points_y_x[i][0] + tmp->y) < size &&
			(tmp->points_y_x[i][1] + tmp->x) < size)
		{
			if (field[tmp->points_y_x[i][0] + tmp->y]
				[tmp->points_y_x[i][1] + tmp->x] == '.')
				i++;
			else if ((tmp->points_y_x[i][1] + tmp->x) < size - 1)
				move_tetri(tmp, &i, 1);
			else
				move_tetri(tmp, &i, 2);
		}
		else
			return (0);
	}
	return (1);
}

static void		place_tetrimino(t_tet *tmp, char ***t_field)
{
	int i;

	i = 0;
	while (i < 4)
	{
		*(*(*t_field + tmp->points_y_x[i][0] + tmp->y) +
			(tmp->points_y_x[i][1] + tmp->x)) = tmp->what;
		i++;
	}
}

static char		**algoritm(char **t_field, t_tet *tmp, int size)
{
	char	**map;

	if (tmp == NULL)
		return (t_field);
	while (tmp->y < size)
	{
		tmp->x = 0;
		while (tmp->x < size)
		{
			if (is_tet_fit(t_field, tmp, size))
			{
				place_tetrimino(tmp, &t_field);
				map = algoritm(t_field, tmp->next, size);
				if (map)
					return (map);
				t_field = remove_tetri(t_field, tmp);
			}
			tmp->x += 1;
		}
		tmp->y += 1;
	}
	tmp->x = 0;
	tmp->y = 0;
	return (NULL);
}

void			total(t_tet *head, int sum_tet)
{
	char	**res;
	char	**t_field;
	int		min_size;
	int		size;

	size = 2;
	res = NULL;
	t_field = NULL;
	min_size = sum_tet * 4;
	while (min_size > size * size)
		size++;
	t_field = new_field(t_field, size);
	while (!(res = algoritm(t_field, head, size)))
	{
		size++;
		ft_memdel((void **)&t_field);
		t_field = new_field(t_field, size);
	}
	print_field(res);
	free_t_tet(&head);
}
