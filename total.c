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

char	**remove_tetri(char **t_field, t_tet *tmp, int size, char what)
{
	int i = 0;

	while (i < 4)
	{
		if (t_field[(tmp)->points_y_x[i][0]][(tmp)->points_y_x[i][1]] == what)
			t_field[(tmp)->points_y_x[i][0]][(tmp)->points_y_x[i][1]] = '.';
		i++;
	}
	return (t_field);
}


static void delet_wrong_tetr(char **t_field, t_tet **tmp, int i, int x, int y)
{
	while (i--)
		t_field[(*tmp)->points_y_x[i][0] + y][(*tmp)->points_y_x[i][1] + x] = '.';
}

static char **place_tetrimino(t_tet *tmp, int size, char what, char **t_field)
{
	int i; // счетчик по кординатам
	int x;
	int y;

	y = 0;
	i = 0;
	x = 0;
	if ((tmp) == NULL)
		return (t_field);
	while (i < 4) // если фигура с отрицательным иксом
	{
		if (((tmp)->points_y_x[i][1] + x) < 0)
		{
			x++;
			i = 0;
		}
		i++;
	}
	i = 0;
	while (i < 4)
	{
			if ((tmp->points_y_x[i][0] + y) < size && (tmp->points_y_x[i][1] + x) < size)
			{
				if (t_field[(tmp)->points_y_x[i][0] + y][(tmp)->points_y_x[i][1] + x] == '.')
				{
					t_field[(tmp)->points_y_x[i][0] + y][(tmp)->points_y_x[i][1] + x] = what; // для функции удалить
					i++;
				}
				else if (((tmp)->points_y_x[i][1] + x) <size - 1)
				{
					delet_wrong_tetr(t_field, &tmp, i, x, y);
					x++;
					i = 0;
				}
				else if (((tmp)->points_y_x[i][0] + y) < size - 1)
				{
					delet_wrong_tetr(t_field, &tmp, i, x, y); // нужно вставить это в оба случая, исправило ошибку с фигурами в файле fсck
					x = 0;
					i = 0;
					y++;
				}
			}
			else
			{
				delet_wrong_tetr(t_field, &tmp, i, x, y);
				return (NULL);
			}
	}
	return (t_field);
}

static  char **algoritm(char **t_field, t_tet *head, int size, char what)
{
	t_tet *tmp;
	int x;
	int y = 0;
	char **map = NULL;

	tmp = head;
	if (tmp == NULL)
		return (t_field);
	while (y < size) {
		x = 0;
		while (x < size) {
			if ((map = place_tetrimino(tmp, size, what++, t_field)) != NULL)
				t_field = algoritm(t_field, tmp->next, size, what);
			if (t_field)
				return (t_field);
			t_field = remove_tetri(map, tmp, size, what);
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
    char what = 'A';

    res = NULL;
	t_field = NULL;
    min_size = sum_tet * 4; // мин размер поля = (кол-во фигур*4)
    while (min_size > size * size) // т,к, нам нужен квадрат
    	size++;
    t_field = new_field(t_field, size);
    while (!(res = algoritm(t_field, head, size, what))) // получаем конечное поле с расположеными фигурами
    {
        size++;
        ft_memdel((void **)&t_field); // подумать
        t_field = new_field(t_field, size);
    }
    print_field(res);
    free(t_field);// nad pochistit'
}
