/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquek <wquek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:48:15 by wquek             #+#    #+#             */
/*   Updated: 2024/06/21 16:48:21 by wquek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digit(unsigned int n)
{
	int	count;

	count = 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*allocate_mem(int *count)
{
	char	*str;

	*count += 1;
	str = malloc(*count);
	if (!str)
		return (NULL);
	return (str);
}

static char	*min_int_or_zero(unsigned int n)
{
	char	*str;
	char	*str1;
	char	*src;
	int		len;

	len = 12;
	src = "-2147483648";
	if (n == 0)
	{
		len = 2;
		src = "0";
	}
	str = malloc(len);
	if (!str)
		return (NULL);
	str1 = str;
	while (--len)
		*str1++ = *src++;
	*str1 = '\0';
	return (str);
}

char	*ft_itoa_unsigned(unsigned int n)
{
	int		remainder;
	char	*str;
	char	*str1;
	int		count;

	if (n == 0)
		return (min_int_or_zero(n));
	count = count_digit(n);
	str = allocate_mem(&count);
	if (!str)
		return (NULL);
	*(str + --count) = '\0';
	str1 = str;
	while (n)
	{
		remainder = n % 10;
		*(str1 + --count) = remainder + 48;
		n /= 10;
	}
	return (str);
}
