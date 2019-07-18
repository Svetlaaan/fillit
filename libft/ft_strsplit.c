/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboggs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:48:39 by fboggs            #+#    #+#             */
/*   Updated: 2019/05/17 15:10:10 by fboggs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_lenofword(char *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s++ != c)
		len++;
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**out;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(out = (char **)malloc(sizeof(char *) * ft_cntwrds((char *)s, c) + 1)))
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
		{
			if (!(out[i++] = ft_strsub(s, 0, ft_lenofword((char *)s, c))))
			{
				ft_deltwodimarray(out, i);
				return (NULL);
			}
		}
		while (*s && *s != c)
			s++;
	}
	out[i] = NULL;
	return (out);
}
