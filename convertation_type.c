/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertation_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskostyl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 15:32:43 by kskostyl          #+#    #+#             */
/*   Updated: 2019/07/30 18:09:21 by kskostyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			convert_f(t_param *par)
{
	par->len_gth[par->length](par);
	par->str = itoa_for_f(par->fnum, (par->precision == -1
				? 6 : par->precision));
	return (1);
}

int			convert_e(t_param *par)
{
	par->len_gth[par->length](par);
	par->str = itoa_for_e(par->fnum, (par->precision == -1
				? 6 : par->precision));
	return (1);
}

int			convert_ee(t_param *par)
{
	int		i;

	i = 0;
	par->len_gth[par->length](par);
	par->str = itoa_for_e(par->fnum,
			(par->precision == -1 ? 6 : par->precision));
	while ((par->str)[i])
	{
		if ((par->str)[i] == 'e')
			(par->str)[i] = 'E';
		i++;
	}
	return (1);
}

int			convert_i_d(t_param *par)
{
	par->len_gth[par->length](par);
	par->str = max_itoa_base(par->num, 10, 0);
	return (1);
}

int			convert_o_u(t_param *par)
{
	par->len_gth[par->length](par);
	par->str = u_max_itoa_base(par->u_num, par->type == 'o' ? 8 : 10, 0);
	return (1);
}
