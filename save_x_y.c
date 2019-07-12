#include <zconf.h>
#include "fillit.h"

static	t_tet	*new_tet_points(t_tet **head, int **points_x_y) // записываем координаты в лист
{
    t_tet *new;
    t_tet *tmp;

    new = NULL;
    tmp = *head;
    if (!head || !points_x_y)
        return (NULL);
    while ((tmp)->next)
        tmp = (tmp)->next;
    new = (t_tet *) malloc(sizeof(t_tet));
    if (new)
    {
        new->points_x_y = points_x_y;
        tmp->next = new;
        new->next = NULL;
    }
    //printf("%d\n", new->points_x_y[0]);
    return (new);
}

static int		**new_arr_points(void) // выделяем память под новый массив координат
{
    int 	**new;
    int		i = 0, j = 0;

    if (!(new = (int**)malloc(4 * sizeof(int*))))
        return (NULL);
    while (i < 4)
    {
        new[i] = (int*)malloc(2 * sizeof(int));
        i++;
    }
    return (new);
}

/*static void    free_listpoints(t_tet **head) // функциф с басика день 11 задание 6
{
    t_tet *current;
    t_tet *tmp;

    current = *head;
    while (current)
    {
        tmp = current->next; // tmp = ссылка на след элемент
        free(current); // чистим current (т,е, в первом случае head)
        current = tmp; // теперь current это слдующий элемент, проходим цикл дальше
    }
    *head = NULL;
}
*/

int				save_x_y(t_tet *head, char *argv)
{
    char 	buf[BUFF_SIZE + 1];
    int		fd;
    char 	field[4][5];
    int		read_chrs;
    int 	**points_x_y;
    int 	x_min = -1, x;
    int 	y_min = -1, y;
    int 	k = 0;
    int 	i = 0;
    t_tet	*tetri;
    int 	sum_t_tet = 0;

    //head = NULL;
    if (!(fd = open(argv, O_RDONLY)))
        return (ERROR);
    if (!(read_chrs = read(fd, buf, BUFF_SIZE)))
        return (ERROR);
    buf[read_chrs] = '\0';
    close(fd);

    points_x_y = new_arr_points();
    while (buf[k] != '\0')
    {
        if (buf[k] == '#')
        {
            if (x_min == -1 && y_min == -1)
            {
                x_min = (k - 21 * sum_t_tet) % 5;
                y_min = (k - 21 * sum_t_tet) / 5; /// МИНУС 21хКОЛ-ВО ФИГУР (ЗАПИСАННЫХ)
            }
            points_x_y[i][0] = (k - 21 * sum_t_tet) / 5 - y_min;
            points_x_y[i][1] = (k - 21 * sum_t_tet) % 5 - x_min;
            i++;
        }
        k++;
    }
    sum_t_tet++;
    //head = new_tet_points(&head, points_x_y);
    head = malloc(sizeof(t_tet));
    if (head)
    {
        head->points_x_y = points_x_y;
        head->next = NULL;
    }
    int j = 0;
    while (j < 4)
    {
        printf("y_x = %i %i\n", head->points_x_y[j][0], head->points_x_y[j][1]);
        j++;
    } //Вывод координат на экран
    tetri = new_tet_points(&head, points_x_y); // не сюда куда-то
   /* while (j < 4)
    {
        printf("y_x = %i %i\n", tet_1->points_x_y[j][0], tet_1->points_x_y[j][1]);
        j++;
    } //Вывод координат на экран
    while(a < 4)
    {
        while(b < 4)
        {
            field[a][b] = '.';
            printf("%c", field[a][b]);
            b++;
        }
        printf("\n");
        field[a][b] = '\0';
        a++;
        b = 0;
    } //Заполняю поле '.'
    printf("\n");
    a = 0, b = 0;

    while (c < 4)
    {
        if ((a + points_x_y[c][0] < 0) || (b + points_x_y[c][1] < 0))
        {
            b++;
            c = 0;
        }
        c++;
    }

    c = 0;
    while (c < 4)
    {
        field[a + points_x_y[c][0]][b + points_x_y[c][1]] = 'A';
        c++;
    }

    a = 0;
    while (a < 4)
    {
        printf("%s\n", field[a]);
        a++;
    } */
    return (1);
}