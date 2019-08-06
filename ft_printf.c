/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskostyl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 20:56:35 by kskostyl          #+#    #+#             */
/*   Updated: 2019/07/30 20:55:16 by kskostyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *str, ...)
{
	t_param		*par;
	int			k;
	int			len;

	len = 0;
	if (!(par = ft_memalloc(sizeof(t_param))))
		return (0);
	va_start(par->param, str);
	table(par);
	table_2(par);
	prin_tf_2(&str, par, &k, &len);
	va_end(par->param);
	ft_memdel((void **)&par);
	return (len);
}

void			prin_tf_2(const char **s, t_param *par, int *k, int *len)
{
	while (**s)
	{
		*k = 0;
		while ((*s)[*k] != '%' && (*s)[*k] != 0)
			*k += 1;
		if (*k)
			write(1, *s, *k);
		*len += *k;
		*s += *k;
		if (**s)
		{
			*s += 1;
			characterize((char **)s, par);
			*k = ft_strlen(par->str);
			if (*k)
				write(1, par->str, *k);
			*len += *k;
			if (par->c)
			{
				write(1, "\0", 1);
				*len += 1;
			}
			ft_memdel((void **)&(par->str));
		}
	}
}

void			table(t_param *par)
{
	(par->types)['i'] = &convert_i_d;
	(par->adj_str)['i'] = &ft_edit_diu;
	(par->types)['d'] = &convert_i_d;
	(par->adj_str)['d'] = &ft_edit_diu;
	(par->types)['o'] = &convert_o_u;
	(par->adj_str)['o'] = &ft_edit_oxx;
	(par->types)['u'] = &convert_o_u;
	(par->adj_str)['u'] = &ft_edit_diu;
	(par->types)['x'] = &convert_x_x;
	(par->adj_str)['x'] = &ft_edit_oxx;
	(par->types)['X'] = &convert_x_x;
	(par->adj_str)['X'] = &ft_edit_oxx;
	(par->types)['s'] = &convert_s;
	(par->adj_str)['s'] = &ft_edit_s;
	(par->types)['c'] = &convert_c;
	(par->adj_str)['c'] = &ft_edit_cp;
	(par->types)['p'] = &convert_p;
	(par->adj_str)['p'] = &ft_edit_cp;
}

void			table_2(t_param *par)
{
	(par->types)['%'] = &convert_proc;
	(par->adj_str)['%'] = &ft_edit_cp;
	(par->types)['f'] = &convert_f;
	(par->adj_str)['f'] = &ft_edit_fee;
	(par->types)['e'] = &convert_e;
	(par->adj_str)['e'] = &ft_edit_fee;
	(par->types)['E'] = &convert_e;
	(par->adj_str)['E'] = &ft_edit_fee;
	(par->len_gth)['l'] = &cast_length_l;
	(par->len_gth)['L'] = &cast_length_lll;
	(par->len_gth)['h'] = &cast_length_h;
	(par->len_gth)['H'] = &cast_length_hh;
	(par->len_gth)['A'] = &cast_length_ll;
	(par->len_gth)['j'] = &cast_length_j;
	(par->len_gth)['z'] = &cast_length_z;
	(par->len_gth)[0] = &cast_length_zero;
}
