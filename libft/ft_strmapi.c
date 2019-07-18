/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboggs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:04:28 by fboggs            #+#    #+#             */
/*   Updated: 2019/04/12 21:28:24 by fboggs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*bro;
	size_t	i;

	i = 0;
	if (s != NULL && f != NULL)
	{
		bro = ft_strnew(ft_strlen(s));
		if (!bro)
			return (NULL);
		while (s[i])
		{
			bro[i] = (*f)(i, s[i]);
			i++;
		}
		return (bro);
	}
	return (NULL);
}
