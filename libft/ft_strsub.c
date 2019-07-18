/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboggs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 20:17:17 by fboggs            #+#    #+#             */
/*   Updated: 2019/05/17 15:10:10 by fboggs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh;
	size_t	l;

	if (s == NULL)
		return (NULL);
	l = ft_strlen(s);
	if ((start + len) <= l)
	{
		fresh = (char *)malloc(sizeof(char) * (len + 1));
		if (fresh == NULL)
			return (NULL);
		else if (fresh)
		{
			fresh = ft_strncpy(fresh, s + start, len);
			fresh[len] = '\0';
		}
		return (fresh);
	}
	return (NULL);
}
