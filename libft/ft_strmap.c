/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboggs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:44:04 by fboggs            #+#    #+#             */
/*   Updated: 2019/04/12 21:34:05 by fboggs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*bro;
	size_t	i;

	i = 0;
	if (s != NULL && f != NULL)
	{
		bro = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (bro == NULL)
			return (NULL);
		while (s[i] != '\0')
		{
			bro[i] = (*f)(s[i]);
			i++;
		}
		bro[i] = '\0';
		return (bro);
	}
	return (NULL);
}
