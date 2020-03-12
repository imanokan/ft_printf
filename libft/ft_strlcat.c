/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:01:45 by imanoka-          #+#    #+#             */
/*   Updated: 2019/05/14 11:09:02 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char		*pdst;
	const char	*psrc;
	size_t		n;
	size_t		dlen;

	pdst = dest;
	psrc = src;
	n = size;
	while (*pdst != '\0' && n-- != 0)
		pdst++;
	dlen = pdst - dest;
	n = size - dlen;
	if (n == 0)
		return (dlen + ft_strlen(src));
	while (*psrc != '\0')
	{
		if (n != 1)
		{
			*pdst++ = *psrc;
			n--;
		}
		psrc++;
	}
	*pdst = '\0';
	return (dlen + (psrc - src));
}
