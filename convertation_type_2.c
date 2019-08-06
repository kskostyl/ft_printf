/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertation_type_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskostyl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 19:35:40 by kskostyl          #+#    #+#             */
/*   Updated: 2019/07/30 02:09:21 by kskostyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		double_convertation(t_param *par)
{
	if (par->type == 'f')
	{
		cast_length_f(par);
		par->str = itoa_for_f(par->fnum,
				(par->precision == -1 ? 6 : par->precision));
		return (1);
	}
	if (par->type == 'e' || par->type == 'E')
	{
		cast_length_f(par);
		if (par->type == 'e')
		{
			par->str = itoa_for_e(par->fnum,
					(par->precision == -1 ? 6 : par->precision));
		}
		else
		{
			par->str = for_tobige(par->fnum,
					(par->precision == -1 ? 6 : par->precision));
		}
		return (1);
	}
	return (0);
}

void	cast_length_f(t_param *par)
{
	if (par->length == 0)
		par->fnum = (double)(va_arg(par->param, double));
	else if (par->length == 3 || par->length == 5)
		par->fnum = (long double)(va_arg(par->param, long double));
}
