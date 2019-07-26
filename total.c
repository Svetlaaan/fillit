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

char	**remove_tetri(char **t_field, t_tet *tmp, int x, int y)
{
	int i = 0;

	while (i < 4)
	{
		if ((t_field[(tmp)->points_y_x[i][0] + y][(tmp)->points_y_x[i][1] + x]) != '.')
			t_field[(tmp)->points_y_x[i][0] + y][(tmp)->points_y_x[i][1] + x] = '.';
		i++;
	}
	return  (t_field);
}

static int		is_tet_fit(char **field, t_tet *tmp, int size, int *x, int *y)
{
	int i = 0;

	while (i < 4)
	{
		if (((tmp)->points_y_x[i][0] + *y) < size && ((tmp)->points_y_x[i][1] + *x) < size)
		{
			if (field[(tmp)->points_y_x[i][0] + *y][(tmp)->points_y_x[i][1] + *x] == '.')
				i++;
			else
			if (((tmp)->points_y_x[i][1] + *x) < size)
			{
				while (i--)
					field[(tmp)->points_y_x[i][0] + *y][(tmp)->points_y_x[i][1] + *x] = '.';
				*x += 1;
				i = 0;
			}
			else if (((tmp)->points_y_x[i][0] + *y) < size)
			{
				*x = 0;
				i = 0;
				*y += 1;
			}
		}
		else
			return (0);
	}
	return (1);
}

static void		place_tetrimino(t_tet *tmp, char ***t_field, int x, int y) //записываем тетримин на поле tmp, size, what++, &t_field, &x, &y
{
	int i = 0;

	while (i < 4)
	{
		*(*(*t_field + tmp->points_y_x[i][0] + y) + (tmp->points_y_x[i][1] + x)) = tmp->what;
		i++;
	}
}


static  char **algoritm(char **t_field, t_tet *head, int size)
{
	t_tet *tmp;
	int x;
	int y = 0;
	char **map;

	map = NULL;
	tmp = head;
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
				map = algoritm(t_field, tmp->next, size); // если работать с t_field, то он пнредается пустой
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

void    total(t_tet *head, int sum_tet)
{
    char	**res;
    char	**t_field;
    int		min_size;
    int		size = 2;// минимальный размер стороны поля
   // char what = 'A';

    res = NULL;
	t_field = NULL;
    min_size = sum_tet * 4; // мин размер поля = (кол-во фигур*4)
    while (min_size > size * size) // т,к, нам нужен квадрат
    	size++;
    t_field = new_field(t_field, size);
    while (!(res = algoritm(t_field, head, size))) // получаем конечное поле с расположеными фигурами
    {
        size++;
        ft_memdel((void **)&t_field); // подумать
        t_field = new_field(t_field, size);
    }
    print_field(res);
    free(t_field);// nad pochistit'
}
