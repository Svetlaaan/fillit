#include "fillit.h"

static int		**new_arr_points(void) // выделяем память под новый массив координат
{
	int 	**new;
	int		i = 0;

	if (!(new = (int**)malloc(4 * sizeof(int*))))
		return (NULL);
	while (i < 4)
	{
		new[i] = (int*)malloc(2 * sizeof(int));
		i++;
	}
	return (new);
}

static	t_tet	*new_tet_points(char what) // записываем координаты в лист
{
    t_tet *new;

    if (!(new = (t_tet*)malloc(sizeof(t_tet))))
        return (NULL);
    new->points_y_x = new_arr_points();
    new->y_min = -1;
    new->x_min = -1;
  //  new->map_x = 0;
  //  new->map_y = 0;
    new->next = NULL;
    new->prev = NULL;
    new->what = what;
    return (new);
}

static void		print_cootdinats(t_tet *head)
{
	int i = 0;
	while (head->next != NULL)
	{
		while (i < 4)
		{
			printf("y_x %i %i\n", head->points_y_x[i][0], head->points_y_x[i][1]);
			i++;
		}
		printf("\n");
		head = head->next;
		i = 0;
	} //выводим координаты в листах
}

static void		fill_t_tet_xy(char *buf, t_tet **tmp)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4 )
	{
		if ((*(buf + j)) == '#')
		{
			if ((*tmp)->y_min == -1 && (*tmp)->x_min == -1)
			{
				(*tmp)->y_min = j / 5;
				(*tmp)->x_min = j % 5;
				printf("y min  %d\n", (*tmp)->y_min);
				printf(" x-min %d\n", (*tmp)->x_min);
			}
			(*tmp)->points_y_x[i][0] = j / 5 - (*tmp)->y_min;
			(*tmp)->points_y_x[i][1] = j % 5 - (*tmp)->x_min;
			i++;
		}
		j++;
	}
}

t_tet				*save_x_y(char *buf, int sum_tetriminos, t_tet **head)
{
	int 	j = 0;
	t_tet	*tmp;
	t_tet	*prev_tet_tmp;
	int 	sum_t_tet = 1;
	char what;

	what = 'A';
	printf("sum_tetriminos = %i\n", sum_tetriminos);
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
		{
			free(&tmp);
			return (NULL); //ОТФРИШИТЬ В СЛУЧАЕ ОШИБКИ
		}
		tmp = tmp->next;
		tmp->prev = prev_tet_tmp;
		j = 21 * sum_t_tet;
		sum_t_tet++;
	}
	print_cootdinats(*head); //выводим координаты
	return (*head);
}