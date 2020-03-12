/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 18:32:07 by imanoka-          #+#    #+#             */
/*   Updated: 2019/05/14 11:09:59 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int k;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0')
	{
		j = 0;
		k = i;
		while (haystack[i] != '\0' && needle[j] != '\0'
				&& haystack[i] == needle[j])
		{
			i++;
			j++;
		}
		if (needle[j] == '\0')
			return (((char *)haystack + k));
		i = k;
		i++;
	}
	return (0);
}
