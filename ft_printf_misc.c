/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_misc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquek <wquek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:28:34 by wquek             #+#    #+#             */
/*   Updated: 2024/07/05 23:13:44 by wquek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_c(char c, int *count)
{
	ft_putchar_fd(c, 1);
	(*count)++;
}

void	ft_print_s(char *str, int *count)
{
	if (!str)
		str = "(null)";
	ft_putstr_fd(str, 1);
	*count += ft_strlen(str);
}

void	ft_print_i(int n, int *count)
{
	char	*str;

	str = ft_itoa(n);
	ft_print_s(str, count);
	free(str);
}

void	ft_print_u(unsigned int n, int *count)
{
	char	*str;

	str = ft_itoa_unsigned(n);
	ft_print_s(str, count);
	free(str);
}
