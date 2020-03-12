/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:41:29 by imanoka-          #+#    #+#             */
/*   Updated: 2019/05/14 15:26:56 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char		*ptr;

	ptr = ((char *)malloc(sizeof(*ptr) * size + 1));
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, '\0', size + 1);
	return (ptr);
}
