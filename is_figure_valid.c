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

int				is_figure_valid(char *buf)
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
