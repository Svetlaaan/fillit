/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboggs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 22:01:08 by fboggs            #+#    #+#             */
/*   Updated: 2019/05/17 15:10:10 by fboggs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}
