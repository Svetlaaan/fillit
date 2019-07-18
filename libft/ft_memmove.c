/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboggs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:10:54 by fboggs            #+#    #+#             */
/*   Updated: 2019/05/17 15:10:10 by fboggs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_s;
	const char	*src_s;
	size_t		i;

	dst_s = (char *)dst;
	src_s = (const char *)src;
	i = 0;
	if (dst_s < src_s)
	{
		while (i < len)
		{
			dst_s[i] = src_s[i];
			i++;
		}
	}
	else
		while (len > 0)
		{
			dst_s[len - 1] = src_s[len - 1];
			len--;
		}
	return (dst_s);
}
