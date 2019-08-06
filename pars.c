/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskostyl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 02:27:40 by kskostyl          #+#    #+#             */
/*   Updated: 2019/07/30 20:10:06 by kskostyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pars(char **format, t_param *par)
{
	flags_pars(format, par);
	width_pars(format, par);
	precision_pars(format, par);
	length_pars(format, par);
	par->type = **format;
	*format += 1;
}

void	precision_pars(char **format, t_param *par)
{
	par->precision = -1;
	if (**format != '.')
		return ;
	*format += 1;
	if (**format == '*')
	{
		par->precision = va_arg(par->param, int);
		*format += 1;
		return ;
	}
	par->precision = ft_atoi(*format);
	while (**format >= '0' && **format <= '9')
		*format += 1;
	return ;
}

void	flags_pars(char **format, t_param *par)
{
	char	*s;
	int		i;

	s = "#0- +";
	ft_bzero(par->flags, sizeof(par->flags));
	i = 0;
	while (s[i])
		par->flags[i++] = 0;
	i = 0;
	while (s[i])
	{
		if (**format == s[i])
		{
			(par->flags)[i] = 1;
			*format += 1;
			i = 0;
			continue ;
		}
		i++;
	}
	return ;
}

void	length_pars(char **format, t_param *par)
{
	par->length = 0;
	if (**format == 'h')
	{
		if (*(*format + 1) == 'h')
			par->length = 'H';
		else
			par->length = 'h';
	}
	else if (**format == 'l')
	{
		if (*(*format + 1) == 'l')
			par->length = 'A';
		else
			par->length = 'l';
	}
	else if (**format == 'L')
		par->length = 'L';
	else if (**format == 'j')
		par->length = 'j';
	else if (**format == 'z')
		par->length = 'z';
	if (par->length == 'H' || par->length == 'A')
		*format += 2;
	else if (par->length != 0)
		*format += 1;
}

void	width_pars(char **format, t_param *par)
{
	par->width = 0;
	if (**format == '*')
	{
		par->width = va_arg(par->param, int);
		*format += 1;
		return ;
	}
	if (**format >= '1' && **format <= '9')
		par->width = ft_atoi(*format);
	while (**format >= '0' && **format <= '9')
		*format += 1;
	return ;
}
