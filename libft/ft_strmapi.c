/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:19:34 by imanoka-          #+#    #+#             */
/*   Updated: 2019/05/14 14:22:38 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s1;
	unsigned int	i;

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
			s1[i] = f(i, s1[i]);
			i++;
		}
	}
	return (s1);
}
