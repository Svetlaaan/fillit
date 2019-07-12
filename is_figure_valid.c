#include "fillit.h"

int		is_figure_valid(const char *buf, int sum_tet)
{
    int		x = 0;
    int 	y = 0;
    int		i = 0;
    int 	valid_num = -1;
    int 	fig_num = 0;

    while (buf[i] != '\0' )
    {
        while (y < 4)
        {
            while (buf[i] != '\n')
            {
                if (buf[i] == '#')
                {
                    valid_num++;
                    if (x < 3 && buf[i + 1] == '#')
                        valid_num++;
                    if (y < 3 && buf[i + 5] == '#')
                        valid_num++;
                }
                i++;
                x++;
            }
            y++;
            i++;
            x = 0;
        }
        if (valid_num < 6 || valid_num > 7)
            return (ERROR);
        valid_num = -1;
        y = 0;
        x = 0;
        if (buf[i] != '\0')
            i++;
        fig_num++;
    }
    return (1);
}