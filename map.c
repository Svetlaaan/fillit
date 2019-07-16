#include "fillit.h"

char    **new_field(char **field, int size)
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
        field[y][x] = '\0';
        y++;
    }
    field[y] = 0;
    return (field);
}

void    print_field(char **field)
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

char	**algoritm(char **t_field, t_tet *head, int size)
{
    int		x;
    int		y;
    char	**field;

    field = NULL;
    y = 0;
    if (head->next == NULL)
        return (t_field);// ne tak
    while (y < size)
    {
        x = 0;
        while (x < size)
        {
            if (check_tetri(t_field, tetri, size))
                field = algoritm(insert_tetri(t_field, head, size), head->next, size);
            if (field)
                return (field);
            t_field = remove_tetri(t_field, tetri, size);
            x++;
        }
        y++;
    }
    return (NULL);
}

void    total(t_tet *head)
{
    char **res;
    char **t_field;
    int size;

    res = NULL;
    size = 2, // мин размер поля
    t_field = NULL;
    t_field = new_field(t_field, size);
    while (!(res = algoritm(t_field, &head, size)))
    {
        size++;
        ft_memdel((void **)t_field);
        t_field = new_field(t_field, size);
    }
    print_field(res);
}
