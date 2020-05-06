/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprint.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <imanoka-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 14:22:52 by imanoka-          #+#    #+#             */
/*   Updated: 2020/03/12 15:46:37 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "./libft/libft.h"
#include <stdio.h>
typedef struct  s_spec
{
	char *spec;
	int  plus;
	int  moins;
	int  zero;
	int  space;
	int  hash;
	int  len; 
	int  len_arg;
	int  n; //pour check binary
	va_list a_list;
	char type; 


}		t_spec;

	



int		conversion_specifier(t_spec *all);
int 		type_spec(char c);
char		*fill_0(t_spec *all);
int		int_in_str(t_spec *all);
int		check_binary(t_spec *all);
char		*fill_space(t_spec *all);
int 		ft_printf(const char *format, ...);
int		flag_exist(const char *format, t_spec *all);
int		flag_simple(t_spec *all);
int 		specifier_c(t_spec *all, ...);
int		specifier_s(t_spec *all, ...);
int		specifier_p(t_spec *all, ...);
