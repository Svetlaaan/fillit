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

static	t_tet	*new_tet_points(char what)
{
	t_tet *new;

	if (!(new = (t_tet*)malloc(sizeof(t_tet))))
		return (NULL);
	new->points_y_x = new_arr_points();
	new->y_min = -1;
	new->x_min = -1;
	new->next = NULL;
	new->prev = NULL;
	new->what = what;
	return (new);
}

static void		fill_t_tet_xy(char *buf, t_tet **tmp)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		if ((*(buf + j)) == '#')
		{
			if ((*tmp)->y_min == -1 && (*tmp)->x_min == -1)
			{
				(*tmp)->y_min = j / 5;
				(*tmp)->x_min = j % 5;
			}
			(*tmp)->points_y_x[i][0] = j / 5 - (*tmp)->y_min;
			(*tmp)->points_y_x[i][1] = j % 5 - (*tmp)->x_min;
			i++;
		}
		j++;
	}
}

static void		next(t_tet **tmp, t_tet **prev_tet_tmp, int *j, int *sum_t_tet)
{
	*tmp = (*tmp)->next;
	(*tmp)->prev = *prev_tet_tmp;
	*j = 21 * *sum_t_tet;
	*sum_t_tet += 1;
}

t_tet			*save_x_y(char *buf, int sum_tetriminos, t_tet **head)
{
	int		j;
	t_tet	*tmp;
	t_tet	*prev_tet_tmp;
	int		sum_t_tet;
	char	what;

	sum_t_tet = 1;
	j = 0;
	what = 'A';
	if (!(tmp = new_tet_points(what)))
		return (NULL);
	what++;
	*head = tmp;
	while (buf[j] != '\0')
	{
		fill_t_tet_xy(buf + j, &tmp);
		if (sum_t_tet == sum_tetriminos)
			break ;
		prev_tet_tmp = tmp;
		if (!(tmp->next = new_tet_points(what++)))
			free_t_tet(&tmp);
		next(&tmp, &prev_tet_tmp, &j, &sum_t_tet);
	}
	return (*head);
}
