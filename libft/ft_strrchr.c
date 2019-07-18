/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboggs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:15:45 by fboggs            #+#    #+#             */
/*   Updated: 2019/04/10 17:33:10 by fboggs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *what;

	what = NULL;
	while (*s)
	{
		if (*s == (char)c)
			what = (char *)s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return (what);
}
