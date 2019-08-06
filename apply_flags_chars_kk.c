/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags_chars_kk.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskostyl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 23:36:53 by kskostyl          #+#    #+#             */
/*   Updated: 2019/07/30 00:12:33 by kskostyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_edit_s(t_param *par)
{
	size_t		len;
	char		*append;

	len = ft_strlen(par->str);
	if (len > (size_t)par->precision && par->precision != -1)
	{
		append = ft_strndup(par->str, par->precision);
		ft_memdel((void **)&(par->str));
		par->str = append;
		len = ft_strlen(par->str);
	}
	if ((size_t)par->width > len)
		ft_adjust_width(par, len);
	return ;
}

void			ft_adjust_width(t_param *par, size_t len)
{
	int			i;
	char		*app;
	char		*tmp;

	i = par->width - len;
	if (!(app = ft_memalloc(i + 1)))
		return ;
	ft_memset(app, ' ', i);
	if ((par->flags)[2] == 1)
		tmp = ft_strjoin(par->str, app);
	else
		tmp = ft_strjoin(app, par->str);
	ft_memdel((void **)&(par->str));
	ft_memdel((void **)&app);
	par->str = tmp;
}

void			ft_edit_cp(t_param *par)
{
	size_t		len;
	int			i;
	char		*app;
	char		*tmp;

	len = ft_strlen(par->str);
	i = par->width - len;
	if ((size_t)par->width > len)
	{
		if (!(app = ft_memalloc(i + 1)))
			return ;
		ft_memset(app, ' ', i);
		if ((par->flags)[2] == 1)
			tmp = ft_strjoin(par->str, app);
		else
			tmp = ft_strjoin(app, par->str);
		ft_memdel((void **)&(par->str));
		ft_memdel((void **)&app);
		par->str = tmp;
	}
}
