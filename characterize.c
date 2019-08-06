/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characterize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskostyl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 21:15:25 by kskostyl          #+#    #+#             */
/*   Updated: 2019/07/30 21:00:28 by kskostyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	characterize(char **format, t_param *par)
{
	if (**format == '%')
	{
		*format += 1;
		par->str = ft_strdup("%");
		return ;
	}
	pars(format, par);
	if (!(ft_strchr("csdiouxXfpEe%", par->type)))
	{
		par->str = ft_strdup("");
		return ;
	}
	(par->types)[(int)par->type](par);
	(par->adj_str)[(int)par->type](par);
	return ;
}
