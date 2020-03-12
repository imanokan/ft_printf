/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:09:05 by imanoka-          #+#    #+#             */
/*   Updated: 2019/05/14 11:01:56 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	c2;
	size_t			i;
	unsigned char	*s1;

	c2 = (unsigned char)c;
	i = 0;
	s1 = (unsigned char *)s;
	if (!s1 && n < 1)
		return (NULL);
	while (i < n)
	{
		if (s1[i] == c2)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
