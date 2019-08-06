/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_tobige.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskostyl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 23:48:37 by kskostyl          #+#    #+#             */
/*   Updated: 2019/07/25 00:39:27 by kskostyl         ###   ########.fr       */
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
	s[i++] = 'E';
	if (e < 0)
	{
		s[i++] = '-';
		e *= -1;
	}
	else
		s[i++] = '+';
	s[i++] = e / 10 + 48;
	s[i++] = e % 10 + 48;
	return ;
}

static void		r_round(char *s, int i, uintmax_t k, long double number)
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

char			*for_tobige(long double number, int prec)
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
	r_round(s, i, k, number);
	add(s, i, e);
	return (s);
}
