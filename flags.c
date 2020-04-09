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


char fill_0(int len, char *s)
{
    char *s;
    int i;

    i = 0;
    while (i < len)
    {
        //printf(" i : %d\n", i);
        s[i] = '0';
        i++;
    }
    printf(" filled :%s\n",s );
    return (s);
}
char     fill_space(int len, char *s)
{
    char *s;
    int i;

    i = 0;
    while (i  < len)
    {
        s[i] = ' ';
        i++;
    }
    return (s);
}


int     flags(const char *spec)
{
    int i;
    int len;
    i = 0;
    char *s;
    char c;
    va_list a_list;

    //s = (char *)malloc(sizeof(char) * 256);
    va_start(a_list, format)
   // c = va_arg(a_list, char);
    //strcpy(s,c);
    while (spec[i] '\0')
    len = atoi(spec);
    spec[1] == '-' ? ft_strjoin(s,fill_space(len,s)) : i++;
    spec[1] == '0' ? ft_strjoin(s,filll_space(len,s)) : i++;

    if (i < len)
        s = (char *)malloc(sizeof(char) * len);
        fill_space(len - 1, s); //pour char
        fill_space(len - ft_strlen(arg), s);
        i++;
    }

    return (0);

}



int flags(const char *str)
{
	while (*str)
	{
		if (str[i] == '%' && str[i + 1] == '-');
		 	flags_min();
		else if (str[i] == '%' && str[i + 1] == ' +')
			flags_plus();
		else if (str[i] == '%' && str[i + 1] == ' ')
			flags_space();
		else if (str[i] == '%' && str[i + 1] ==  '0')
			flags_zero();
		else if (str[i] == '%' && str[i + 1] == '#')
			flag_hashtag();
	}
}
