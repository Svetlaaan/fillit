/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboggs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:49:54 by fboggs            #+#    #+#             */
/*   Updated: 2019/04/16 16:03:21 by fboggs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_len_of_number(int n)
{
	int len;

	len = 1;
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char		ft_str_of_numbers(int nb, char *str, int i, int sign)
{
	int number;

	number = nb;
	str[i] = '\0';
	if (sign)
		str[0] = '-';
	while (number)
	{
		str[i - 1] = (number % 10) + 48;
		i--;
		number = number / 10;
	}
	return ((char)str);
}

char			*ft_itoa(int n)
{
	char	*out;
	int		len;
	int		sign;

	sign = 0;
	out = NULL;
	if (n == -2147483648)
	{
		out = ft_strnew(ft_len_of_number(n) + 1);
		ft_strcpy(out, "-2147483648");
		return (out);
	}
	if (n && n < 0)
	{
		n = (n * (-1));
		sign = 1;
	}
	len = ft_len_of_number(n) + sign;
	out = ft_strnew(len);
	if (!out)
		return (NULL);
	if (n == 0)
		*out = '0';
	ft_str_of_numbers(n, out, len, sign);
	return (out);
}
