/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertation_type_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskostyl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 02:05:40 by kskostyl          #+#    #+#             */
/*   Updated: 2019/07/30 14:44:22 by kskostyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			convert_x_x(t_param *par)
{
	par->len_gth[par->length](par);
	par->str = u_max_itoa_base(par->u_num, 16, (par->type == 'x' ? 0 : 1));
	return (1);
}

int			convert_s(t_param *par)
{
	char	*ch_ar;

	if (!(ch_ar = va_arg(par->param, char *)))
		par->str = ft_strdup("(null)");
	else
		par->str = ft_strdup(ch_ar);
	return (1);
}

int			convert_c(t_param *par)
{
	if (par->type == 'c')
		par->str = ft_memalloc(2);
	if (!(par->str[0] = va_arg(par->param, int)))
		par->c = 1;
	if (par->c && par->width)
		par->width -= 1;
	return (1);
}

int			convert_p(t_param *par)
{
	char	*ch_ar;

	ch_ar = max_itoa_base((uintmax_t)(va_arg(par->param, void *)), 16, 0);
	par->str = ft_strjoin("0x", ch_ar);
	ft_memdel((void **)&ch_ar);
	return (1);
}

int			convert_proc(t_param *par)
{
	par->str = ft_strdup("%");
	return (1);
}
