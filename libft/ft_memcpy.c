/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 12:10:37 by imanoka-          #+#    #+#             */
/*   Updated: 2019/05/14 10:57:07 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	char				*ptr;
	const char			*ptr2;

	ptr = dest;
	ptr2 = src;
	i = 0;
	while (i < n)
	{
		ptr[i] = ptr2[i];
		i++;
	}
	return (dest);
}
