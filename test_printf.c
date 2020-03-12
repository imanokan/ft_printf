/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <imanoka-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:31:54 by imanoka-          #+#    #+#             */
/*   Updated: 2020/03/12 15:36:48 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>


void ft_malloc(const char *str)
{
	char *s;

	s = (char *)malloc(sizeof(char) * strlen(str));
	strcpy(s, str);
	printf(" new s : %s\n",s);

}

int main(void)
{
	const char *str;

	str = "ish ish";
	ft_malloc(str);
	return (0);

}
