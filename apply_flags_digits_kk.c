/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags_digits_kk.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskostyl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 23:30:54 by kskostyl          #+#    #+#             */
/*   Updated: 2019/07/30 01:18:37 by kskostyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_edit_oxx_2(t_param *par, size_t *len)
{
	char	*tmp;

	if (par->flags[3] == 1 || par->flags[4] == 1)
	{
		tmp = ft_strjoin((par->flags[4] == 1 ? "+" : " "), par->str);
		ft_memdel((void **)&(par->str));
		par->str = tmp;
	}
	*len = ft_strlen(par->str);
	if (par->width > par->precision && par->precision != -1 && par->width)
		ft_adjust_signs(par);
	if ((size_t)par->width > *len)
		ft_adjust_width_num(par, *len);
	ft_adjust_signs(par);
	return ;
}

static void			ft_edit_fee_2(t_param *par, size_t *len)
{
	char		*tmp;

	if (((par->flags)[3] == 1 || (par->flags)[4] == 1) && par->fnum >= 0)
	{
		tmp = ft_strjoin((par->flags[4] == 1 ? "+" : " "), par->str);
		ft_memdel((void **)&(par->str));
		par->str = tmp;
	}
	*len = ft_strlen(par->str);
	if (par->precision > par->precision && par->precision != -1 && par->width)
		ft_adjust_signs(par);
	if ((size_t)par->width > *len)
		ft_adjust_width_num(par, *len);
	ft_adjust_signs(par);
}

void				ft_edit_oxx(t_param *par)
{
	size_t		len;

	len = ft_strlen(par->str);
	if (par->precision == 0 && (par->type == 'o' ?
				par->flags[0] != 1 : 1) && par->u_num == 0)
		par->str[0] = 0;
	if (len < (size_t)par->precision && par->precision != -1)
	{
		ft_adjust_precision_num(par, len);
		len = ft_strlen(par->str);
	}
	if (par->flags[0] == 1 && par->u_num != 0)
	{
		ft_add_ox(par);
		len = ft_strlen(par->str);
	}
	ft_edit_oxx_2(par, &len);
	return ;
}

void				ft_edit_fee(t_param *par)
{
	size_t		len;

	len = ft_strlen(par->str);
	if (par->precision == 0 && par->fnum == 0)
		par->str[0] = 0;
	if (len < (size_t)par->width && par->width != 0)
	{
		ft_adjust_precision_num(par, len);
		len = ft_strlen(par->str);
	}
	ft_edit_fee_2(par, &len);
	return ;
}
