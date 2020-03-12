/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 18:02:21 by imanoka-          #+#    #+#             */
/*   Updated: 2019/05/14 15:09:05 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countwords(char const *str, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	if (str && c)
	{
		while (str[i])
		{
			while (str[i] == c)
				i++;
			if (str[i] != c && str[i] != '\0')
				count++;
			while (str[i] != c && str[i] != '\0')
				i++;
		}
	}
	return (count);
}

static int		get_word_len(char const *str, char c)
{
	size_t len;

	len = 0;
	if (str && c)
	{
		while (str[len] != c && str[len])
			len++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**str;

	if (!s || !(str = (char **)malloc(sizeof(*str) *
					(ft_countwords(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_countwords(s, c))
	{
		k = 0;
		while (s[j] == c)
			j++;
		if (!(str[i] = ft_strnew(get_word_len(&s[j], c) + 1)))
			return (NULL);
		while (s[j] != c && s[j])
			str[i][k++] = s[j++];
		str[i][k] = '\0';
		i++;
	}
	str[i] = 0;
	return (str);
}
