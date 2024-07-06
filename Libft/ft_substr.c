/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquek <wquek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 13:33:37 by wquek             #+#    #+#             */
/*   Updated: 2024/06/02 15:20:27 by wquek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*src;
	char			*dest;
	char			*head;
	size_t			str_len;

	str_len = ft_strlen((char *)s);
	if (str_len < start)
		len = 0;
	else if (str_len - start < len)
		len = str_len - start;
	src = (char *)s + start;
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	head = dest;
	while (len-- && *src)
		*dest++ = *src++;
	*dest = '\0';
	return (head);
}
