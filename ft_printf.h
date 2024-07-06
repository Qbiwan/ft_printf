/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquek <wquek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:58:46 by wquek             #+#    #+#             */
/*   Updated: 2024/06/22 11:36:43 by wquek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEXSMALL "0123456789abcdef"
# define HEXLARGE "0123456789ABCDEF"
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include "Libft/libft.h"

int		ft_printf(const char *format, ...);
void	ft_print_c(char c, int *count);
void	ft_print_s(char *str, int *count);
void	ft_print_i(int n, int *count);
void	ft_print_p(void *ptr, int *count);
void	ft_print_u(unsigned int n, int *count);
void	ft_print_x(int n, int *count, char spec);
char	*ft_itoa_unsigned(unsigned int n);
#endif
