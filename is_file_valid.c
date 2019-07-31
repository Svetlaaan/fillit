#include "fillit.h"

static void		valid_sum(char *buf, int y, int *valid_num)
{
	int x;
	int i;

	x = 0;
	i = 0;
	while (*(buf + i) != '\n')
	{
		if (*(buf + i) == '#')
		{
			*valid_num += 1;
			if (x < 3 && *(buf + i + 1) == '#')
				*valid_num += 1;
			if (y < 3 && *(buf + i + 5) == '#')
				*valid_num += 1;
		}
		i++;
		x++;
	}
}

static int		is_figure_valid(char *buf)
{
	int		y;
	int		i;
	int		valid_num;
	int		fig_num;

	fig_num = 0;
	valid_num = -1;
	i = 0;
	y = 0;
	while (buf[i] != '\0')
	{
		while (y < 4)
		{
			valid_sum((buf + i + (5 * y)), y, &valid_num);
			y++;
		}
		if (valid_num < 6 || valid_num > 7)
			return (ERROR);
		valid_num = -1;
		y = 0;
		i += 21;
		fig_num++;
	}
	return (1);
}

static int		is_sum_chrs(char *buffer)
{
	int		sum_sharps;
	int		sum_n;
	int		sum_dots;
	int		i;

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

int				is_file_valid(char *buffer, int read_chrs, int *sum_tetriminos)
{
	int		i;

	i = 0;
	while (*(buffer + i) != '\0')
	{
		if (is_sum_chrs(buffer + i) == 1)
		{
			*sum_tetriminos += 1;
			if ((*(buffer + 20 * *sum_tetriminos +
				(*sum_tetriminos - 1)) == '\n' || (*(buffer + 20 *
				*sum_tetriminos + (*sum_tetriminos - 1)) == '\0')))
				i += 21;
			else
				return (ERROR);
		}
		else
			return (ERROR);
	}
	if (read_chrs == *sum_tetriminos * 20 + (*sum_tetriminos - 1)
	&& is_figure_valid(buffer) == 1)
		return (1);
	return (ERROR);
}
