/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskostyl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 22:27:39 by kskostyl          #+#    #+#             */
/*   Updated: 2019/07/30 23:33:35 by kskostyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# define IS_XX (par->str[i] == 'x' || par->str[i] == 'X')

typedef struct		s_param
{
	va_list			param;
	int				precision;
	short			flags[5];
	int				length;
	int				width;
	intmax_t		num;
	uintmax_t		u_num;
	long double		fnum;
	char			type;
	char			c;
	int				len;
	char			*str;
	int				(*types[127])(struct s_param *);
	int				(*len_gth[127])(struct s_param *);
	void			(*adj_str[127])(struct s_param *);
}					t_param;

void				characterize(char **format, t_param *par);

void				pars(char **format, t_param *par);
void				precision_pars(char **format, t_param *par);
void				flags_pars(char **format, t_param *par);
void				length_pars(char **format, t_param *par);
void				width_pars(char	**format, t_param *par);

int					convert_f(t_param *par);
int					convert_e(t_param *par);
int					convert_ee(t_param *par);
int					convert_i_d(t_param *par);
int					convert_o_u(t_param *par);
int					convert_x_x(t_param *par);
int					convert_s(t_param *par);
int					convert_c(t_param *par);
int					convert_p(t_param *par);
int					convert_proc(t_param *par);

int					cast_length_ll(t_param *par);
int					cast_length_l(t_param *par);
int					cast_length_zero(t_param *par);
int					cast_length_h(t_param *par);
int					cast_length_hh(t_param *par);
int					cast_length_lll(t_param *par);
int					cast_length_j(t_param *par);
int					cast_length_z(t_param *par);

int					ft_printf(const char *str, ...);
void				prin_tf_2(const char **s, t_param *par, int *k, int *len);
void				table(t_param *par);
void				table_2(t_param *par);

void				ft_edit_s(t_param *par);
void				ft_adjust_width(t_param *par, size_t len);
void				ft_edit_cp(t_param *par);

char				*max_itoa_base(intmax_t number, uintmax_t ba_se, int flags);

void				ft_edit_oxx(t_param *par);
void				ft_edit_diu(t_param *par);
void				ft_edit_fee(t_param *par);

void				ft_adjust_signs(t_param *par);
void				ft_adjust_precision_num(t_param *par, size_t len);
void				ft_add_ox(t_param *par);
void				ft_adjust_width_num(t_param *par, size_t len);

int					double_convertation(t_param *par);
void				cast_length_f(t_param *par);

char				*for_tobige(long double number, int prec);
char				*itoa_for_e(long double number, int	prec);

char				*itoa_for_f(long double number, int prec);

char				*u_max_itoa_base(uintmax_t number,
		uintmax_t base, int flag);

#endif
