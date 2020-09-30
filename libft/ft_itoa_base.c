/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <imanoka-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:26:37 by imanoka-          #+#    #+#             */
/*   Updated: 2020/09/30 13:55:38 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	nlen(long long value, int base)
{
	int count;

	count = 0;
	while (value)
	{
		count++;
		value /= base;
	}
	return (count);
}

char				*ft_itoa_base(long long value, int base)
{
	char	*str_base;
	char	*dst;
	int		len;
	int		sign;

	sign = 0;
	str_base = "0123456789abcdef";
	len = nlen(value, base);
	if (base < 2 || base > 16)
		return (NULL);
	if (value == 0)
		return ("0");
	(base == 10 && value < 0) ? sign = 1 && len++ : sign;
	value < 0 ? value = -value : value;
	dst = malloc(sizeof(char) * (len + 1));
	sign ? dst[0] = '-' : 0;
	dst[len] = '\0';
	while (value)
	{
		dst[--len] = str_base[value % base];
		value /= base;
	}
	return (dst);
}
