/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquek <wquek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:58:31 by wquek             #+#    #+#             */
/*   Updated: 2024/05/26 15:15:34 by wquek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*s3;
	char			*head;
	unsigned int	i;
	unsigned int	j;

	if (!(s1 && s2))
		return (NULL);
	i = ft_strlen((char *)s1);
	j = ft_strlen((char *)s2);
	head = malloc(i + j + 1);
	if (!head)
		return (NULL);
	s3 = head;
	while (i--)
		*s3++ = *s1++;
	while (j--)
		*s3++ = *s2++;
	*s3 = '\0';
	return (head);
}
