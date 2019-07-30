#include "fillit.h"

void		print_field(char **field)
{
	int		i;

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

static int		read_tetriminos(char *argv, char **buffer)
{
	int		fd;
	int		read_chrs;

	if (!(*(buffer) = ft_memalloc(BUFF_SIZE + 1)))
		return (ERROR);
	if (!(fd = open(argv, O_RDONLY)))
		return (ERROR);
	if (!(read_chrs = read(fd, *buffer, BUFF_SIZE)))
		return (ERROR);
	if (read_chrs == BUFF_SIZE)
		return (ERROR);
	close(fd);
	return (read_chrs);
}

static int		print_mess(int i)
{
	if (i == -1)
		ft_putstr("error\n");
	return (ERROR);
}

int				main(int argc, char **argv)
{
	char	*buffer;
	int		read_chrs;
	int		sum_tet;
	t_tet	*head;

	head = NULL;
	sum_tet = 0;
	if (argc > 2)
		ft_putstr("usage: fillit target_file\n");
	else if ((read_chrs = read_tetriminos(argv[1], &buffer)) == -1)
		print_mess(-1);
	else
	{
		if (is_file_valid(buffer, read_chrs, &sum_tet) == 1)
		{
			if (!(save_x_y(buffer, sum_tet, &head)))
				print_mess(-1);
			total(head, sum_tet);
		}
		else
			print_mess(-1);
	}
	return (0);
}
