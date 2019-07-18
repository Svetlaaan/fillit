/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboggs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:17:59 by fboggs            #+#    #+#             */
/*   Updated: 2019/05/17 15:10:10 by fboggs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*dst_s;
	char			*src_s;
	size_t			i;
	char			*ci;

	dst_s = (char *)dst;
	src_s = (char *)src;
	i = 0;
	ci = NULL;
	while (i < n && ci == 0)
	{
		dst_s[i] = src_s[i];
		if (src_s[i] == ((char)c))
			ci = dst_s + i + 1;
		i++;
	}
	return ((void *)ci);
}
