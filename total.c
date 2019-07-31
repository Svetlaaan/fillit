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

static void		move_tetri(int *x, int *y, int *i, int a)
{
	if (a == 1)
	{
		*x += 1;
		*i = 0;
	}
	else if (a == 2)
	{
		*x = 0;
		*i = 0;
		*y += 1;
	}
}

static int		is_tet_fit(char **field, t_tet *tmp, int size, int *x, int *y)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if ((tmp->points_y_x[i][0] + *y) < size &&
			(tmp->points_y_x[i][1] + *x) < size)
		{
			if (field[tmp->points_y_x[i][0] + *y]
				[tmp->points_y_x[i][1] + *x] == '.')
				i++;
			else if ((tmp->points_y_x[i][1] + *x) < size - 1)
				move_tetri(x, y, &i, 1);
			else
				move_tetri(x, y, &i, 2);
		}
		else
			return (0);
	}
	return (1);
}

static void		place_tetrimino(t_tet *tmp, char ***t_field, int x, int y)
{
	int i;

	i = 0;
	while (i < 4)
	{
		*(*(*t_field + tmp->points_y_x[i][0] + y) +
			(tmp->points_y_x[i][1] + x)) = tmp->what;
		i++;
	}
}

static char		**algoritm(char **t_field, t_tet *tmp, int size)
{
	int		x;
	int		y;
	char	**map;

	y = 0;
	if (tmp == NULL)
		return (t_field);
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (is_tet_fit(t_field, tmp, size, &x, &y))
			{
				place_tetrimino(tmp, &t_field, x, y);
				map = algoritm(t_field, tmp->next, size);
				if (map)
					return (map);
				t_field = remove_tetri(t_field, tmp, x, y);
			}
			x++;
		}
		y++;
	}
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
