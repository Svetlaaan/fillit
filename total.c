#include "fillit.h"

static char    **new_field(char **field, int size)
{
    int x;
    int y;

    y = 0;
    field = (char **)malloc(sizeof(char *) * size + 1);
    if (!field)
        return (NULL);
    while (y < size)
    {
        if (!(field[y] = (char *) malloc(sizeof(char) * size + 1)))
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

static void	delete_field(char **field)
{
	size_t	i;

	i = 0;
	while (field[i])
	{
		free(field[i]);
		++i;
	}
	free(field);
}

static void    print_field(char **field)
{
    int i;

    i = 0;
    if (field == NULL)
    {
        ft_putendl("ERROR");
        return ;
    }
    i = 0;
    while (field[i] != 0)
    {
        ft_putendl(field[i]);
        i++;
    }
}

static char **algoritm(char **t_field, t_tet *head, int size)
{
	int x;
	int y = 0;
	int i;
	int tetr = 0;
	t_tet *tmp;
	char what = 'A';

	if (head == NULL)
		return (t_field);
	tmp = head;
		x = 0;
		i = 0;
		while (i < 4) // если фигура с отрицательным иксом
		{
			if ((tmp->points_y_x[i][1] + x) < 0)
			{
				x++;
				i = 0;
			}
			i++;
		}
		i = 0;
		while (i < 4)
		{
			if ((tmp->points_y_x[i][0] + y) < 0)
				y += 1;
			else if ((tmp->points_y_x[i][1] + x) < 0)
				x += 1;
			if ((tmp->points_y_x[i][0] + y) < size && (tmp->points_y_x[i][1] + x) < size)
				t_field[tmp->points_y_x[i][0] + y][tmp->points_y_x[i][1] + x] = what;
			else
				return (NULL);
			i++;
		}
	return (t_field);
}

void    total(t_tet *head, int sum_tet)
{
    char	**res;
    char	**t_field;
    int		min_size;
    int		size = 2;// минимальный размер стороны поля

    res = NULL;
	t_field = NULL;
    min_size = sum_tet * 4; // мин размер поля = (кол-во фигур*4)
    while (min_size > size * size) // т,к, нам нужен квадрат
    	size++;
    t_field = new_field(t_field, size);
    while (!(res = algoritm(t_field, head, size))) // получаем конечное поле с расположеными фигурами
    {
        size++;
        ft_memdel((void **)t_field);
        t_field = new_field(t_field, size);
    }
    print_field(res);
}
