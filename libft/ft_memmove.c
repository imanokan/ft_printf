/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:44:27 by imanoka-          #+#    #+#             */
/*   Updated: 2019/05/14 11:00:46 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*ptr;
	unsigned char		*ptr2;

	i = 0;
	ptr = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	if (ptr < ptr2)
		while (i < len)
		{
			ptr[i] = ptr2[i];
			i++;
		}
	else
	{
		while (len-- > 0)
			ptr[len] = ptr2[len];
	}
	return (dst);
}
