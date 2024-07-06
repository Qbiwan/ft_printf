/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquek <wquek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:34:40 by wquek             #+#    #+#             */
/*   Updated: 2024/06/06 23:36:57 by wquek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	j = ft_strlen(src);
	k = ft_strlen(dest);
	i = k;
	if (k >= size)
		return (size + j);
	while ((i < size - 1) && *src)
		*(dest + i++) = *src++;
	*(dest + i) = '\0';
	return (k + j);
}
