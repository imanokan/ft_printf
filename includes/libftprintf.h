/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imanoka- <imanoka-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 14:22:52 by imanoka-          #+#    #+#             */
/*   Updated: 2020/09/29 14:48:39 by imanoka-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "../libft/libft.h"
#include <stdio.h>
#include <stdint.h>
#include <limits.h>
//#include "/mnt/c/Users/Audrey/Desktop/manoka/libft/libft.h"

typedef struct 	s_conv
{
	long long p;
	char *s;
	char *c;
	signed int d;
	unsigned int x;
	unsigned int u;
	double f; //float de va_arg
	unsigned int o; // unsigned int
	double deci;
	double fl;  //float utilisé pour les calculs
	int ent; //partie entière float
	int fl_int; // partie float arrondie caster en un int
	char *fl_str; // float en str
	char *x_str;
	char *o_str;
	char *p_str;
	char *tmp_str; // width_precision chaine pour les modif
}			t_conv;

typedef struct  s_spec
{
	char *spec;
	char *spec1;
	int  plus;
	int  moins;
	int  zero;
	int  space;
	int  hash;
	int width;
	char h;
	char l;
	char ll;
	char L;
	char hh;
	int w;
	int  len;
	int  len_arg;
	int  vision;
	int  ision;
	int  pision;
	int  n; //pour check binary
	va_list a_list;
	t_conv *conv;
	char type;
	char *s_filled;
	char *s_filled_p;
	int 	precision;
	char *s_filled_d;
	char *filled_float;
	char 	p; // char + ou - pour all->plus
	int check;
	int point;
	int wp; // check si w et p existe en meme temps
	int isneg;
	int check1; //check doublon de signes
	int stop;
	int esp; //flag space
	char *s_filled_f;

}		t_spec;

/*
typedef struct	s_conv;
{
	long *p;
	char *c;
	char *s;
	signed int d;
	unsigned int x;
	unsigned int u;
	signed int o;
	float f;
}		t_conv;
*/




int		cut_str(const char *format, int *i, t_spec *all);
int		conversion_specifier(t_spec *all);
int 		type_spec(char c);
int		check_binary(t_spec *all);
//char		*fill_space(t_spec *all);
int 		ft_printf(const char *format, ...);
void		flag_exist(t_spec *all);
int		flag_simple(t_spec *all);
int 		specifier_c(t_spec *all);
int		specifier_s(t_spec *all);
int		specifier_p(t_spec *all);
int		specifier_d(t_spec *all);
int specifier_u(t_spec *all);
int		specifiers_f(t_spec *all);
int		size_nb_unsigned(unsigned int n);
int 	size_nb(int n);
void		flag_exist_bis(const char *format, t_spec *all);
void		flag_hh_ll_d(t_spec *all);
void		flag_hh_ll_u(t_spec *all);
int 		fill_width(t_spec *all);
int			fill_precision(t_spec *all);
int 		fill_width_plus(t_spec *all);
int 	fnct_output_s(t_spec *all);
int			ft_atoi_bis(char *str, int *i);
void 	ft_precision(t_spec *all);
int		fill_width_diouxx(t_spec *all);
void flag_corr(t_spec *all);
void space_plus(t_spec *all);
int     width_unsigned(t_spec *all, unsigned int nb);
int 	width_signed(t_spec *all, signed int nb);
int 	width_precision_signed(t_spec *all, long long nb);
int 	precision_signed(t_spec *all, signed int nb);
int   precision_unsigned(t_spec *all, unsigned int nb);
int width_precision_unsigned(t_spec *all, unsigned int nb);
void check_type(t_spec *all); //pour width - le bon specifier
int specifier_o(t_spec *all);
int specifier_x(t_spec *all);
int sep_int_deci(t_spec *all);
int round_up(t_spec *all);
int	 round_up_bis(t_spec *all);
char 	*join_float(t_spec *all);
int  width_s(t_spec *all, char *s);
int precision_s(t_spec *all, char *s);
int width_precision_s(t_spec *all, char *s);
void space_plus_p(t_spec *all);
long double check_l_lupper(t_spec *all);
uintmax_t check_l_ll_h_hh_unsigned(uintmax_t nb, t_spec *all);
intmax_t check_l_ll_h_hh(intmax_t nb, t_spec *all);
int		specifier_percent(const char *format, t_spec *all);
int w_p_unsigned_char(t_spec *all, unsigned char s);
int p_unsigned_char(t_spec *all, unsigned char s);
int  w_unsigned_char(t_spec *all, unsigned char s);
int   precision_ox(t_spec *all, char *s);
int width_precision_ox(t_spec *all, char *s);
int cut_str_bis(const char *format, int *i, t_spec *all);
void  flag_exist_1(t_spec *all);
int	width_s_plus(t_spec *all, char *s);
void   width_min_s(t_spec *all, char *s);
void	width_precision_s_moins(t_spec *all,char *s);
int		width_float(t_spec *all);
