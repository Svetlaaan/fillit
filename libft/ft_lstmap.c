/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboggs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:10:41 by fboggs            #+#    #+#             */
/*   Updated: 2019/04/19 13:29:14 by fboggs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*new;

	if (lst && *f)
	{
		list = f(lst);
		new = list;
		while (lst->next)
		{
			lst = lst->next;
			if (!(list->next = f(lst)))
			{
				free(list->next);
				return (NULL);
			}
			list = list->next;
		}
		return (new);
	}
	return (NULL);
}
