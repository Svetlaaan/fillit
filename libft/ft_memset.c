/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboggs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:16:54 by fboggs            #+#    #+#             */
/*   Updated: 2019/08/07 11:11:17 by fboggs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	cou;
	char	*be;

	cou = 0;
	be = (char *)b;
	if (len == 0)
		return (be);
	while (cou < len)
	{
		be[cou] = (unsigned char)c;
		cou++;
	}
	return ((void *)be);
}
