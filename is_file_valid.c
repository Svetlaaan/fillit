#include "fillit.h"

int 	is_file_valid(char *argv, int *p_sum_fig)
{
    int		fd;
    int		read_chrs = 0;
    int		sum_chrs = 0;
    int		sum_sharps = 0;
    int		sum_tetriminos = 0;
    int 	i = 0,j = 0;
    char 	buffer[BUFF_SIZE + 1];

    if (!(fd = open(argv, O_RDONLY)))
        return (ERROR);
    if (!(read_chrs = read(fd, buffer, BUFF_SIZE)))
        return (ERROR);
    buffer[read_chrs] = '\0';
    close(fd);
    if (read_chrs == BUFF_SIZE)
        return (ERROR);
    else
    {
        while (buffer[j] != '\0')
        {
            while (i < 4 && buffer[j] != '\n' && sum_chrs < 5)
            {
                if (buffer[j] == '.' || buffer[j] == '#')
                {
                    sum_chrs++;
                    if (buffer[j] == '#')
                        sum_sharps++;
                    j++;
                }
                else
                    return (ERROR);
            }
            if (sum_chrs != 4 )
                return (ERROR);
            if (i < 4 && buffer[j] == '\n' )
            {
                sum_chrs = 0;
                i++;
                j++;
            }
            if (i == 4)
            {
                if (buffer[j] == '\n' || buffer[j] == '\0')
                {
                    if (sum_sharps != 4)
                        return (ERROR);
                    if (buffer[j] == '\n')
                        j++;
                    sum_tetriminos++;
                    sum_chrs = 0;
                    sum_sharps = 0;
                    i = 0;
                }
                else
                    return (ERROR);
            }
        }
        printf("Figures sum = %i\n", sum_tetriminos);
    }
    *p_sum_fig = sum_tetriminos; /// для того чтобы передать кол-во фигур в другую ф-ю
    if (read_chrs == sum_tetriminos * 20 + (sum_tetriminos - 1) && is_figure_valid(buffer, sum_tetriminos))
        return (1);
    return (ERROR);
}