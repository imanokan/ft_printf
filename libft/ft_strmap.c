/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:12:09 by imanoka-          #+#    #+#             */
/*   Updated: 2019/05/14 14:20:29 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*s1;
	size_t	i;

	if (!s)
		return (NULL);
	s1 = ft_strdup((const char *)s);
	if (s1 == NULL)
		return (NULL);
	i = 0;
	if (s1 && f)
	{
		while (s1[i] != '\0')
		{
			s1[i] = f(s1[i]);
			i++;
		}
	}
	return (s1);
}
