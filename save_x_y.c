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

static	t_tet	*new_tet_points(void) // записываем координаты в лист
{
    t_tet *new;

    if (!(new = (t_tet*)malloc(sizeof(t_tet))))
        return (NULL);
    new->points_y_x = new_arr_points();
    new->y_min = -1;
    new->x_min = -1;
    new->next = NULL;
    new->prev = NULL;
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
		head = (t_tet *)head->next;
		i = 0;
	} //выводим координаты в листах
}

void *save_x_y(char *argv, char *buf, int sum_tetriminos, t_tet *head)
{
    int 	j = 0;
    int 	i = 0;
    //t_tet	*head = NULL;
    t_tet	*tmp;
    t_tet	*prev_tet_tmp = NULL;
    int 	sum_t_tet = 0;

	tmp = new_tet_points();
	head = tmp;
	while (buf[j] != '\0')
	{
		while (i < 4)
		{
			if (buf[j] == '#')
			{
				if (tmp->y_min == -1 && tmp->x_min == -1)
				{
					tmp->y_min = (j - 21 * sum_t_tet) / 5; /// МИНУС 21xКОЛ-ВО ФИГУР (ЗАПИСАННЫХ)
					tmp->x_min = (j - 21 * sum_t_tet) % 5;
				}
				tmp->points_y_x[i][0] = (j - 21 * sum_t_tet) / 5 - tmp->y_min;
				tmp->points_y_x[i][1] = (j - 21 * sum_t_tet) % 5 - tmp->x_min;
				i++;
			}
			j++;
		}
		prev_tet_tmp = tmp;
		tmp->next = new_tet_points();
		tmp = (t_tet *) tmp->next;
		tmp->prev = prev_tet_tmp;
		sum_t_tet++;
		i = 0;
		if (sum_tetriminos == sum_t_tet)
			break ;
		j = 21 * sum_t_tet;
	}
	print_cootdinats(head); //выводим координаты
	return (head);
}