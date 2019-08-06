/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertation_length_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskostyl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 01:50:01 by kskostyl          #+#    #+#             */
/*   Updated: 2019/07/30 20:19:35 by kskostyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			cast_length_ll(t_param *par)
{
	if (par->type == 'i' || par->type == 'd')
		par->num = (long long)(va_arg(par->param, long long));
	else
		par->u_num =
			(unsigned long long)(va_arg(par->param, unsigned long long));
	return (1);
}

int			cast_length_j(t_param *par)
{
	if (par->type == 'i' || par->type == 'd')
		par->num = (intmax_t)(va_arg(par->param, intmax_t));
	else
		par->u_num = (uintmax_t)(va_arg(par->param, uintmax_t));
	return (1);
}

int			cast_length_z(t_param *par)
{
	if (par->type == 'i' || par->type == 'd')
		par->num = (size_t)(va_arg(par->param, size_t));
	else
		par->u_num = (size_t)(va_arg(par->param, size_t));
	return (1);
}
