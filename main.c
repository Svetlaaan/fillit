#include "fillit.h"

static int 	read_tetriminos(char *argv, char **buffer)
{
	int		fd;
	int		read_chrs;

	if (!(*(buffer) = ft_memalloc(BUFF_SIZE + 1)))
		return (ERROR);
	if (!(fd = open(argv, O_RDONLY)))
		return (ERROR);
	if (!(read_chrs = read(fd, *buffer, BUFF_SIZE)))
		return (ERROR);
	if (read_chrs == BUFF_SIZE) /////ОШИБКА КОЛИЧЕСТВА СИМВОЛОВ
		return (ERROR);
	close(fd);
	return (read_chrs);
}

int		main(int argc, char **argv)
{
	char	*buffer;
	int		read_chrs;
	int		sum_tet;
	t_tet  	*head = NULL;

	sum_tet = 0;
	if ((read_chrs = read_tetriminos(argv[1], &buffer)) == -1)
		return (ERROR);
	if (argc > 2)
		ft_putstr("usage: fillit target_file");
	else
	{
		if (is_file_valid(buffer, &sum_tet) == 1) //
		{
			ft_putstr("Tetriminos and file are valid\n");
			if (!(save_x_y(argv[1], buffer, sum_tet, &head)))
				return (ERROR);
			total((t_tet *)&head, sum_tet);
		}
		else
			ft_putstr("error\n");
	}
	return (0);
}