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
#include <string.h>
/*
 *
void ft_malloc(const char *str)
{
	char *s;

	//s = (char *)malloc(sizeof(char) * strlen(str));
	strcpy(s, str);
	printf(" new s : %s\n",s);

}
*/
int main(void)
{
	int i;
	char c;

	c = '0';
	int s = 0;
	char d = '-';
	char p = '+';
	char sp = ' ';
	char *str = "0-AV";
	i = 0;
/*	while (str[i] != '\0')
	{
		c && d ? s = 1 : s;
		p && sp ? s = 1 : s;
		i++;
	}*/
//	printf("%d\n",s);µ
	printf("octal : %o\n", 6553);
	printf("decimal : %d\n",0101001);
//	printf("%0-10d",i); 
	return (0);

}
