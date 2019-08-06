/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags_digits_util_kk.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskostyl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 23:39:21 by kskostyl          #+#    #+#             */
/*   Updated: 2019/07/30 01:39:16 by kskostyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_adjust_signs(t_param *par)
{
	int			i;

	i = -1;
	while (par->str[++i])
	{
		if (par->str[i] == '-' && i != 0 && par->str[0] != ' ' &&
				par->str[i - 1] != 'e' && par->str[i - 1] != 'E')
		{
			par->str[i] = par->str[0];
			par->str[0] = '-';
		}
		else if (IS_XX && i > 1 && par->str[i - 2] == '0')
		{
			par->str[i] = par->str[i - 2];
			par->str[i - 1] = par->str[i - 2];
			par->str[0] = '0';
			par->str[1] = (par->type == 'x' ? 'x' : 'X');
		}
		else if (par->str[i] == '+' && i != 0 && par->str[0] != ' ' &&
				par->str[i - 1] != 'e' && par->str[i - 1] != 'E')
		{
			par->str[i] = par->str[0];
			par->str[0] = '+';
		}
	}
}

void			ft_adjust_precision_num(t_param *par, size_t len)
{
	char		*ze_ro;
	char		*tmp;
	size_t		spa_se;

	spa_se = (par->type == 'e' || par->type == 'E' || par->type == 'f' ? \
			par->width : par->precision);
	ze_ro = ft_memalloc(spa_se - len + 1);
	ft_memset(ze_ro, '0', spa_se - len);
	tmp = ft_strjoin(ze_ro, par->str);
	ft_memdel((void **)&(par->str));
	ft_memdel((void **)&ze_ro);
	par->str = tmp;
}

void			ft_add_ox(t_param *par)
{
	char		*tmp;

	if (par->type == 'o')
	{
		tmp = ft_strjoin("0", par->str);
		ft_memdel((void **)&(par->str));
		par->str = tmp;
	}
	else
	{
		tmp = ft_strjoin((par->type == 'x' ? "0x" : "0X"), par->str);
		ft_memdel((void **)&(par->str));
		par->str = tmp;
	}
	return ;
}

void			ft_adjust_width_num(t_param *par, size_t len)
{
	int			i;
	char		*app;
	char		*tmp;

	i = par->width - len;
	if (!(app = ft_memalloc(i + 1)))
		return ;
	ft_memset(app,
			(par->flags[1] == 1 && par->flags[2] == 0 &&
			((par->precision > par->width) || par->precision == -1)
			? '0' : ' '), i);
	if (par->flags[2] == 1)
		tmp = ft_strjoin(par->str, app);
	else
		tmp = ft_strjoin(app, par->str);
	ft_memdel((void **)&(par->str));
	ft_memdel((void **)&app);
	par->str = tmp;
	return ;
}
