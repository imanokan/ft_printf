/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <imanoka-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:10:22 by imanoka-          #+#    #+#             */
/*   Updated: 2020/04/09 18:00:58 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"   


char *fill_0(int space)
{
    char *s;
    int i;
	
// do not forget to free
    i = 0;
   if (!(s = malloc(sizeof(char*) * space + 1)))
	return (-1);
    while (i < space)
    {
        s[i] = '0';
        i++;
    }
    return (s);
}
char     *fill_space(int space)
{
    char *s;
    int i;

    i = 0;
if (!( s = malloc(sizeof(char *) * space + 1)))
	return (-1);
    while (i  < space)
    {
        s[i] = ' ';
        i++;
    }
    return (s);
}

int 	int_in_str(char *spec)
{
	int i;
	int n:
	n = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (isdigit(spec[i]))
			n = n * 10 + (spec[i] - '0');
		i++;
	}
	return (n);

}
