/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertation_length.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskostyl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 15:35:47 by kskostyl          #+#    #+#             */
/*   Updated: 2019/07/30 20:51:56 by kskostyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			cast_length_lll(t_param *par)
{
	par->fnum = (long double)(va_arg(par->param, long double));
	return (1);
}

int			cast_length_l(t_param *par)
{
	if (par->type == 'i' || par->type == 'd')
		par->num = (long)(va_arg(par->param, long));
	else if (par->type == 'f' || par->type == 'e' || par->type == 'E')
		par->fnum = (long double)(va_arg(par->param, long double));
	else
		par->u_num = (unsigned long)(va_arg(par->param, unsigned long));
	return (1);
}

int			cast_length_zero(t_param *par)
{
	if (par->type == 'i' || par->type == 'd')
		par->num = (int)(va_arg(par->param, int));
	else if (par->type == 'f' || par->type == 'e' || par->type == 'E')
		par->fnum = (double)(va_arg(par->param, double));
	else
		par->u_num = (unsigned int)(va_arg(par->param, unsigned int));
	return (1);
}

int			cast_length_h(t_param *par)
{
	if (par->type == 'i' || par->type == 'd')
		par->num = (short)(va_arg(par->param, int));
	else
		par->u_num = (unsigned short)(va_arg(par->param, unsigned int));
	return (1);
}

int			cast_length_hh(t_param *par)
{
	if (par->type == 'i' || par->type == 'd')
		par->num = (signed char)(va_arg(par->param, int));
	else
		par->u_num = (unsigned char)(va_arg(par->param, unsigned int));
	return (1);
}
