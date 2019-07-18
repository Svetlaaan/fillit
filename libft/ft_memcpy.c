/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboggs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:54:48 by fboggs            #+#    #+#             */
/*   Updated: 2019/04/11 15:12:42 by fboggs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	cou;
	char	*dst_s;
	char	*src_s;

	cou = 0;
	dst_s = (char *)dst;
	src_s = (char *)src;
	while (cou < n)
	{
		dst_s[cou] = src_s[cou];
		cou++;
	}
	return ((void*)dst);
}
