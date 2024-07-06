/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquek <wquek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 22:30:02 by wquek             #+#    #+#             */
/*   Updated: 2024/06/06 22:39:16 by wquek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*assign_memory(char	*head, char	*tail)
{
	char	*new_str;

	if (head > tail)
		new_str = malloc(1);
	else
	{
		new_str = malloc(tail - head + 2);
	}
	return (new_str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*head;
	char	*tail;
	char	*new_str;
	size_t	i;

	head = (char *)s1;
	while (*head && ft_strchr(set, *head))
		head++;
	tail = (char *)s1 + ft_strlen((char *)s1) - 1;
	while (*tail && ft_strchr(set, *tail))
		tail--;
	new_str = assign_memory(head, tail);
	if (!new_str)
		return (NULL);
	i = 0;
	while (head <= tail)
		new_str[i++] = *head++;
	new_str[i] = '\0';
	return (new_str);
}
