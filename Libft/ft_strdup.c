/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquek <wquek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:49:40 by wquek             #+#    #+#             */
/*   Updated: 2024/05/26 14:59:09 by wquek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*s1;
	char	*head;
	char	*d;

	s1 = (char *)s;
	i = 0;
	while (*s1++)
		i++;
	head = malloc(i + 1);
	if (!head)
		return (NULL);
	d = head;
	while (i--)
		*d++ = *s++;
	*d = '\0';
	return (head);
}
