/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboggs <fboggs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 14:08:03 by fboggs            #+#    #+#             */
/*   Updated: 2019/08/07 13:05:44 by fboggs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			print_field(char **field, int size)
{
	int		i;

	if (field == NULL)
	{
		ft_putendl("ERROR");
		return ;
	}
	i = 0;
	while (i < size)
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
	if (read_chrs == BUFF_SIZE || read_chrs < 20)
		return (ERROR);
	close(fd);
	return (read_chrs);
}

static void		final_free(t_tet **head, char **buffer)
{
	free_t_tet_head(head);
	free(*buffer);
	*buffer = NULL;
}

int				main(int argc, char **argv)
{
	char	*buffer;
	int		read_chrs;
	int		sum_tet;
	t_tet	*head;

	buffer = NULL;
	sum_tet = 0;
	if (argc == 1 || argc > 2)
		ft_putstr("usage: fillit target_file\n");
	else if ((read_chrs = read_tetriminos(argv[1], &buffer)) == -1)
		ft_putstr("error\n");
	else
	{
		if (is_file_valid(buffer, read_chrs, &sum_tet) == 1)
		{
			if (!(save_x_y(buffer, sum_tet, &head)))
				ft_putstr("error\n");
			if (!(map(head, sum_tet)))
				ft_putstr("error\n");
		}
		else
			ft_putstr("error\n");
	}
	final_free(&head, &buffer);
	return (0);
}
