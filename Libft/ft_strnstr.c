/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquek <wquek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 20:02:57 by wquek             #+#    #+#             */
/*   Updated: 2024/06/06 11:44:36 by wquek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	compare_str(char *set_p, char *s1_sub_p,
size_t sublen)
{
	int	found;

	found = 1;
	while (*set_p)
	{
		if (*s1_sub_p++ != *set_p++ || !sublen--)
		{
			found = 0;
			break ;
		}
	}
	return (found);
}

char	*ft_strnstr(const char *s1, const char *set, size_t len)
{
	char	*set_p;
	char	*s1_sub_p;
	size_t	sublen;

	s1_sub_p = NULL;
	if (!*set)
		return ((char *)s1);
	if (len > ft_strlen(s1))
		len = ft_strlen(s1);
	while (len)
	{
		set_p = (char *)set;
		sublen = len;
		s1_sub_p = (char *)s1;
		if (*s1 == *set_p && compare_str(set_p, s1_sub_p, sublen))
			return ((char *)s1);
		s1++;
		len--;
	}
	return (NULL);
}
