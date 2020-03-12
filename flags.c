/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <imanoka-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:10:22 by imanoka-          #+#    #+#             */
/*   Updated: 2020/03/12 15:17:02 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


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
