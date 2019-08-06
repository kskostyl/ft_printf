/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags_digits_2_kk.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskostyl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 01:06:31 by kskostyl          #+#    #+#             */
/*   Updated: 2019/07/30 23:36:21 by kskostyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_edit_diu_2(t_param *par, size_t *len)
{
	char	*tmp;

	if ((par->flags[3] == 1 || par->flags[4] == 1)
			&& par->num >= 0 && par->type != 'u')
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
}

void			ft_edit_diu(t_param *par)
{
	size_t		len;

	len = ft_strlen(par->str);
	if (!(par->type == 'u'))
		(par->num < 0 ? len -= 1 : 0);
	if (par->precision == 0 &&
			(par->type == 'u' ? par->u_num == 0 : par->num == 0))
		par->str[0] = 0;
	if (len < (size_t)par->precision && par->precision != -1)
	{
		ft_adjust_precision_num(par, len);
		len = ft_strlen(par->str);
	}
	ft_edit_diu_2(par, &len);
	return ;
}
