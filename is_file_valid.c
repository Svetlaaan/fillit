#include "fillit.h"

static int		is_sum_chrs(char *buffer)
{
	int sum_sharps;
	int sum_n;
	int sum_dots;
	int i;

	sum_sharps = 0;
	sum_n = 0;
	sum_dots = 0;
	i = 0;
	while (i < 20)
	{
		if (*(buffer + i) == '.')
			sum_dots++;
		if (*(buffer + i) == '#')
			sum_sharps++;
		if (*(buffer + i) == '\n')
			sum_n++;
		i++;
	}
	if (sum_sharps == 4 && sum_n == 4 && sum_dots == 12)
		return (1);
	return (0);
}

int 	is_file_valid(char *buffer, int read_chrs, int *sum_tetriminos)
{
	int 	i;

	i = 0;
	while (*(buffer + i) != '\0')
	{
		if	(is_sum_chrs(buffer + i) == 1)
		{
			*sum_tetriminos += 1;
			if ((*(buffer + 20 * *sum_tetriminos + (*sum_tetriminos - 1)) == '\n'
				 || (*(buffer + 20 * *sum_tetriminos + (*sum_tetriminos - 1)) == '\0')))
				i += 21;
			else
				return (ERROR);
		}
		else
			return (ERROR);
	}
	printf("Figures sum = %i\n", *sum_tetriminos);
	if (read_chrs == *sum_tetriminos * 20 + (*sum_tetriminos - 1) && is_figure_valid(buffer) == 1)
		return (1);
	return (ERROR);
}