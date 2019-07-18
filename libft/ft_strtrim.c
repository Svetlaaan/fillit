/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboggs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:02:41 by fboggs            #+#    #+#             */
/*   Updated: 2019/04/15 13:00:45 by fboggs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		ft_is_blank(char *c)
{
	return (*c == ' ' || *c == '\t' || *c == '\n');
}

char			*ft_strtrim(char const *s)
{
	char		*fresh;
	char const	*end;

	if (s == NULL)
		return (NULL);
	end = s + ft_strlen(s) - 1;
	while (ft_is_blank((char *)s))
		s++;
	if (*s == '\0')
		return (ft_strnew(0));
	while (ft_is_blank((char *)end))
		end--;
	fresh = ft_strsub(s, 0, end - s + 1);
	if (fresh == NULL)
		return (NULL);
	return (fresh);
}
