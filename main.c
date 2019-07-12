#include "fillit.h"

int		main(int argc, char **argv)
{
	int file_valid;
	int sum_fig = 56;
	int *p_sum_fig;
	t_tet   *head;

    head = NULL;
    //head->next = NULL;
	p_sum_fig = &sum_fig;

	if (argc > 2)
		printf("usage: fillit target_file");
	else
	{
		file_valid = is_file_valid(argv[1], p_sum_fig);
		if (file_valid == 1)
			printf("Tetriminos and file are valid\n");
		else
			printf("File isn't valid.\n");
	}
	//save_tetriminos(argv[1]);
	save_x_y(head, argv[1]);
	printf("sum_fig = %i\n", sum_fig);
	return (0);
}