/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:54:54 by imanoka-          #+#    #+#             */
/*   Updated: 2019/05/14 11:10:19 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		k;
	int		j;
	char	*hay2;

	hay2 = (char *)haystack;
	if (needle[0] == '\0')
		return (hay2);
	i = 0;
	while (hay2[i] != '\0')
	{
		j = 0;
		k = i;
		while (hay2[i] != '\0' && needle[j] != '\0'
				&& hay2[i] == needle[j] && i < (size_t)len)
		{
			i++;
			j++;
		}
		if (needle[j] == '\0')
			return (&hay2[k]);
		i = k;
		i++;
	}
	return (0);
}
