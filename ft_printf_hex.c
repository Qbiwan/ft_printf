/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquek <wquek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:18:30 by wquek             #+#    #+#             */
/*   Updated: 2024/06/22 13:16:33 by wquek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*choose_hexbase(char spec)
{
	static const char	*hexbase;

	if (spec == 'p' || spec == 'x')
		hexbase = HEXSMALL;
	else if (spec == 'X')
		hexbase = HEXLARGE;
	return (hexbase);
}	

static void	zero_byte_found(char spec, int *count)
{
	if (spec == 'p')
		ft_print_s("(nil)", count);
	else
		ft_print_c('0', count);
}

static int	ft_byte2hex(unsigned char *s, int *start_print, int *i, char spec)
{
	const char		*hexbase;
	int				count;

	count = 0;
	hexbase = choose_hexbase(spec);
	if (((*s / 16) || (*s % 16)) && !*start_print)
	{
		if (spec == 'p')
			ft_print_s("0x", &count);
		if (*s / 16)
			ft_print_c(hexbase[*s / 16], &count);
		ft_print_c(hexbase[*s % 16], &count);
		*start_print = 1;
	}
	else if (*start_print)
	{
		ft_print_c(hexbase[*s / 16], &count);
		ft_print_c(hexbase[*s % 16], &count);
	}
	else if (!*i && !(*s / 16) && !(*s % 16))
		zero_byte_found(spec, &count);
	return (count);
}

void	ft_print_p(void *ptr, int *count)
{
	unsigned char	*s;
	int				i;
	int				start_print;

	s = (unsigned char *)&ptr;
	i = 7;
	start_print = 0;
	while (i >= 0)
	{
		*count += ft_byte2hex((s + i), &start_print, &i, 'p');
		i--;
	}
}

void	ft_print_x(int n, int *count, char spec)
{
	unsigned char	*s;
	int				i;
	int				start_print;

	s = (unsigned char *)&n;
	i = 3;
	start_print = 0;
	while (i >= 0)
	{
		*count += ft_byte2hex((s + i), &start_print, &i, spec);
		i--;
	}
}
