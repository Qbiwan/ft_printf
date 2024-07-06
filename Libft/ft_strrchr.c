/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquek <wquek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:33:34 by wquek             #+#    #+#             */
/*   Updated: 2024/06/06 13:43:47 by wquek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*ptr;
	unsigned char	c1;

	c1 = (unsigned char)c;
	ptr = NULL;
	while (*s || c1 == '\0')
	{
		if (*s == (unsigned char)c1)
		{
			ptr = (char *)s;
			if (!*s)
				break ;
		}
		s++;
	}
	return (ptr);
}
