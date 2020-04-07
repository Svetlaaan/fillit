/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_x_y.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboggs <fboggs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 15:44:13 by fboggs            #+#    #+#             */
/*   Updated: 2019/08/05 15:44:13 by fboggs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		fill_t_tet_xy(char *buf, t_tet **tmp)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		if ((*(buf + j)) == '#')
		{
			if ((*tmp)->y_min == -1 && (*tmp)->x_min == -1)
			{
				(*tmp)->y_min = j / 5;
				(*tmp)->x_min = j % 5;
			}
			(*tmp)->points_y_x[i][0] = j / 5 - (*tmp)->y_min;
			(*tmp)->points_y_x[i][1] = j % 5 - (*tmp)->x_min;
			i++;
		}
		j++;
	}
}

static void		next(t_tet **tmp, t_tet **prev_tet_tmp, int *j, int *sum_t_tet)
{
	*tmp = (*tmp)->next;
	(*tmp)->prev = *prev_tet_tmp;
	*j = 21 * *sum_t_tet;
	*sum_t_tet += 1;
}

t_tet			*save_x_y(char *buf, int sum_tetriminos, t_tet **head)
{
	int		j;
	t_tet	*tmp;
	t_tet	*prev_tet_tmp;
	int		sum_t_tet;
	char	letter;

	sum_t_tet = 1;
	j = 0;
	letter = 'A';
	if (!(tmp = new_tet_points(letter)))
		return (NULL);
	letter++;
	*head = tmp;
	while (buf[j] != '\0')
	{
		fill_t_tet_xy(buf + j, &tmp);
		if (sum_t_tet == sum_tetriminos)
			break ;
		prev_tet_tmp = tmp;
		if (!(tmp->next = new_tet_points(letter++)))
			free_t_tet(&tmp);
		next(&tmp, &prev_tet_tmp, &j, &sum_t_tet);
	}
	return (*head);
}
