/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <imanoka-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:26:37 by imanoka-          #+#    #+#             */
/*   Updated: 2020/03/12 14:07:04 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdlib.h>
// #include <stdio.h>
//
//
// int		find_size(long value, int base)
// {
// 	long len;
//
// 	len = 0;
// 	while (value)
// 	{
// 		len++;
// 		value /= base;
// 	}
// 	return (len);
// }
//
//
// char 	*ft_itoa_base(long value, int base)
// {
// 	char *str_base;
// 	int sign;
// 	long len;
// 	char *ret;
// printf("111 value %ld\n", value);
// 	sign = 0;
// 	len = 0;
// 	str_base = "0123456789ABCDEF";
// 	// len = find_size(value,base);
// 	if (base < 2 || base > 16)
// 		return (0);
// 	//if (base == 10 && value == -2147483648)
// 	//	return ("-2147483648");
// 	if (value == 0)
// 		return (0);
// 	(base == 10  && value < 0)  ? sign = 1 && len++ : len;
// 	value < 0 ? value = -value : value;
// 	len = find_size(value,base);
// 	ret = (char*)malloc(sizeof(char) * (len  + 1));
// 	ret[len] = '\0';
// 	sign ? (ret[0] = '-') : 0;
// 	while (value)
// 	{
// 		ret[--len]= str_base[value % base];
// 		value /= base;
// 	}
// 	printf("ret %s\n", ret);
// 	return (ret);
// }

#include "libft.h"
#include <stdio.h>

static long long	nlen(long long value, int base)
{
	int count = 0;

	while (value)
	{
		count++;
		value /= base;
	}
	return (count);
}

static	char 	*pick_size(char c)
{
	if (c == 'm')
		return ("0123456789abcdef");
	else if (c == 'M')
		return ("0123456789ABCDEF");
	return(NULL);
}

char 			*ft_itoa_base(long long value, int base, char c)
{
	char *str_base;
	char *dst;
//	long long n;
	int len;
	int sign;

	//n = value;
	sign = 0;
	str_base = pick_size(c);
	len = nlen(value, base);
	if (base < 2 || base > 16)
		return(NULL);
	if (value == 0)
		return ("0");
	(base == 10 && value < 0) ? sign = 1 && len++: sign;
	value < 0 ? value = -value: value;
	dst = malloc(sizeof(char) * (len + 1));
	sign ? dst[0] = '-': 0;
	dst[len] = '\0';
	while (value)
	{
		dst[--len] = str_base[value % base];
		value /= base;
	}
	return (dst);
}
