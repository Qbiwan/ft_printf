/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquek <wquek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:17:22 by wquek             #+#    #+#             */
/*   Updated: 2024/06/22 16:48:32 by wquek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	router(char *fmt, va_list ap, int *count)
{
	if (*fmt == 'c')
		ft_print_c(va_arg(ap, int), count);
	else if (*fmt == 's')
		ft_print_s(va_arg(ap, char *), count);
	else if (*fmt == 'p')
		ft_print_p(va_arg(ap, void *), count);
	else if (*fmt == '%')
		ft_print_c('%', count);
	else if (*fmt == 'i' || *fmt == 'd' )
		ft_print_i(va_arg(ap, int), count);
	else if (*fmt == 'u')
		ft_print_u(va_arg(ap, int), count);
	else if (*fmt == 'x')
		ft_print_x(va_arg(ap, int), count, 'x');
	else if (*fmt == 'X')
		ft_print_x(va_arg(ap, int), count, 'X');
}

int	ft_printf(const char *format, ...)
{
	char			*fmt;
	int				count;
	va_list			ap;

	count = 0;
	fmt = (char *)format;
	va_start(ap, format);
	while (*fmt)
	{
		if (*fmt == '%')
			router(++fmt, ap, &count);
		else
			ft_print_c(*fmt, &count);
		fmt++;
	}
	va_end(ap);
	return (count);
}
