#include "fillit.h"

int 	is_file_valid(char *buffer, int *sum_tetriminos)
{
    int		sum_chrs = 0;
    int		sum_sharps = 0;
    int 	i = 0,j = 0;

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
    printf("Figures sum = %i\n", *sum_tetriminos);
    if ((is_figure_valid(buffer)) == 1)
        return (1);
    else
    	return (ERROR);
}