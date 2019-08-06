/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_for_e.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskostyl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 20:41:34 by kskostyl          #+#    #+#             */
/*   Updated: 2019/07/30 02:16:21 by kskostyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		search(long double *number, int *e)
{
	while (*number < 1)
	{
		*e -= 1;
		*number *= 10;
	}
	while (*number > 10)
	{
		*e += 1;
		*number /= 10;
	}
	return ;
}

static void		add(char *s, int i, int e)
{
	s[i++] = 101;
	if (e < 0)
	{
		s[i++] = 45;
		e *= -1;
	}
	else
		s[i++] = 43;
	s[i++] = e / 10 + 48;
	s[i++] = e % 10 + 48;
	return ;
}

static void		round_d(char *s, int i, uintmax_t k, long double number)
{
	i--;
	k = number;
	k *= 10;
	number = number * 10 - k;
	k = number;
	if (k >= 5)
	{
		if (s[i] != 57)
			s[i] += 1;
		else
		{
			while (s[i] == 57)
				s[i--] = 48;
			s[i] += 1;
		}
	}
	return ;
}

char			*itoa_for_e(long double number, int prec)
{
	char		*s;
	int			i;
	int			e;
	uintmax_t	k;

	i = 0;
	e = 0;
	s = ft_memalloc(21 + prec);
	(number < 0 ? (((s[i++] = '-') && (number *= -1))) : 0);
	search(&number, &e);
	s[i++] = number + 48;
	s[i++] = '.';
	while (prec-- > 0)
	{
		k = number;
		k *= 10;
		number = number * 10 - k;
		k = number;
		s[i++] = k + 48;
	}
	round_d(s, i, k, number);
	add(s, i, e);
	return (s);
}
