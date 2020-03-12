/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 16:52:22 by imanoka-          #+#    #+#             */
/*   Updated: 2019/05/14 14:25:27 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*str;
	unsigned int	i;
	size_t			j;

	if (s)
	{
		str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (str == NULL)
			return (NULL);
		i = 0;
		while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i] != '\0')
			i++;
		j = ft_strlen(s) - 1;
		while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && j > i)
			j--;
		str = ft_strsub(s, i, j - (size_t)i + 1);
		return (str);
	}
	return (NULL);
}
