/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquek <wquek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:52:17 by wquek             #+#    #+#             */
/*   Updated: 2024/06/07 16:22:27 by wquek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(int n)
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

static char	*allocate_mem(int is_neg, int *count)
{
	char	*str;

	if (is_neg < 0)
	{
		*count += 2;
		str = malloc(*count);
	}
	else
	{
		*count += 1;
		str = malloc(*count);
	}
	if (!str)
		return (NULL);
	return (str);
}

static int	is_negative(int n)
{
	int	is_neg;

	is_neg = 1;
	if (n < 0)
		is_neg = -1;
	return (is_neg);
}

static char	*min_int_or_zero(int n)
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

char	*ft_itoa(int n)
{
	int		remainder;
	char	*str;
	char	*str1;
	int		is_neg;
	int		count;

	if (n == -2147483648 || n == 0)
		return (min_int_or_zero(n));
	is_neg = is_negative(n);
	n *= is_neg;
	count = count_digit(n);
	str = allocate_mem(is_neg, &count);
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
	if (is_neg < 0)
		*str = '-';
	return (str);
}
