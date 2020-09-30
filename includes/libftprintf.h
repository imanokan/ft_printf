/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <imanoka-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 14:22:52 by imanoka-          #+#    #+#             */
/*   Updated: 2020/09/30 13:48:57 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"
# include <stdio.h>
# include <stdint.h>
# include <limits.h>

typedef struct		s_conv
{
	long long		p;
	char			*s;
	char			*c;
	signed int		d;
	unsigned int	x;
	unsigned int	u;
	double			f;
	unsigned int	o;
	double			deci;
	double			fl;
	int				ent;
	int				fl_int;
	char			*fl_str;
	char			*x_str;
	char			*o_str;
	char			*p_str;
	char			*tmp_str;

}					t_conv;

typedef struct		s_spec
{
	char			*spec;
	char			*spec1;
	int				plus;
	int				moins;
	int				zero;
	int				space;
	int				hash;
	int				width;
	char			h;
	char			l;
	char			ll;
	char			hh;
	int				w;
	int				len;
	int				len_arg;
	int				vision;
	int				ision;
	int				pision;
	va_list			a_list;
	t_conv			*conv;
	char			type;
	char			*s_filled;
	char			*s_filled_p;
	int				precision;
	char			*s_filled_d;
	char			*filled_float;
	char			p;
	int				check;
	int				point;
	int				wp;
	int				isneg;
	int				stop;
	int				esp;
	char			*s_filled_f;

}					t_spec;

/*
** conversion_specifier
*/
int					conversion_specifier(t_spec *all);
intmax_t			check_l_ll_h_hh(intmax_t nb, t_spec *all);
uintmax_t			check_l_ll_h_hh_unsigned(uintmax_t nb, t_spec *all);
long double			check_l_lupper(t_spec *all);

/*
** flag_simple
*/
void				flag_exist(t_spec *all);
void				flag_exist_1(t_spec *all);
void				ft_precision(t_spec *all);
void				flag_corr(t_spec *all);
void				flag_exist_bis(const char *format, t_spec *all);

/*
** format
*/
int					specifier_percent(const char *format, t_spec *all);
void				free_all(t_spec *all);

/*
** ft_printf
*/
int					type_spec(char c);
void				initialisation(t_spec *all);
int					cut_str(const char *format, int *i, t_spec *all);
int					ft_printf(const char *restrict format, ...);

/*
** outils_flags_bis
*/
int					size_nb_unsigned(unsigned int n);
int					size_nb(int n);
void				flag_hh_ll_d(t_spec *all);
void				flag_hh_ll_u(t_spec *all);
int					round_up_bis(t_spec *all);

/*
** outils_flags
*/
int					fill_width_diouxx(t_spec *all);
int					fill_precision(t_spec *all);
void				space_plus(t_spec *all);
void				check_type(t_spec *all);
void				space_plus_p(t_spec *all);

/*
** specifier_d
*/
int					specifier_d(t_spec *all);
int					specifier_x(t_spec *all);
int					specifier_o(t_spec *all);
int					specifier_u(t_spec *all);

/*
** specifiers_f
*/
int					specifiers_f(t_spec *all);
int					width_float(t_spec *all);
int					sep_int_deci(t_spec *all);
char				*join_float(t_spec *all);
int					round_up_mine(t_spec *all);

/*
** specifier_c
*/
int					specifier_p(t_spec *all);
int					specifier_c(t_spec *all);
int					specifier_s(t_spec *all);

/*
** width_precision_di
*/
int					width_signed(t_spec *all, signed int nb);
void				width_signed_moins(t_spec *all, signed int nb);
int					precision_signed(t_spec *all, signed int nb);
int					width_precision_signed(t_spec *all, long long nb);
void				width_precision_signed_moins(t_spec *all, long long nb);

/*
** width_precision_ox
*/
int					precision_ox(t_spec *all, char *s);
int					width_precision_ox(t_spec *all, char *s);
int					width_unsigned(t_spec *all, unsigned int nb);
int					precision_unsigned(t_spec *all, unsigned int nb);
int					width_precision_unsigned(t_spec *all, unsigned int nb);

/*
** width_s
*/
int					width_s_plus(t_spec *all, char *s);
void				width_min_s(t_spec *all, char *s);
int					precision_s(t_spec *all, char *s);
int					width_precision_s(t_spec *all, char *s);
void				width_precision_s_moins(t_spec *all);
#endif
