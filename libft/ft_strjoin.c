/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:55:44 by imanoka-          #+#    #+#             */
/*   Updated: 2019/05/14 15:04:23 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;

	if (s1 && s2)
	{
		if (!(res = (char *)malloc(sizeof(char) * (ft_strlen(s1)
							+ ft_strlen(s2) + 1))))
			return (NULL);
		ft_strcpy(res, s1);
		ft_strcat(res, s2);
		return (res);
	}
	return (NULL);
}
