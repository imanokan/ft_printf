/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 16:22:36 by imanoka-          #+#    #+#             */
/*   Updated: 2019/05/14 11:09:47 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *ptr;

	ptr = (char *)s + ft_strlen(s);
	while (*ptr != c)
	{
		if (ptr == s)
			return (NULL);
		ptr--;
	}
	return (ptr);
}
