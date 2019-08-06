/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_for_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskostyl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 21:34:32 by kskostyl          #+#    #+#             */
/*   Updated: 2019/07/30 02:18:15 by kskostyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*round(char *s, int i, uintmax_t k, long double number)
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
	return (s);
}

static char		r_reversion(char *s)
{
	int		i;
	int		length;

	i = 0;
	length = ft_strlen(s);
	if (s[i] == '-')
		i++;
	while (i < --length)
	{
		s[i] = s[i] ^ s[length];
		s[length] = s[i] ^ s[length];
		s[i] = s[i] ^ s[length];
		i++;
	}
	return (*s);
}

char			*itoa_for_f(long double number, int prec)
{
	char		*s;
	int			i;
	uintmax_t	k;

	i = 0;
	s = ft_memalloc(21 + prec);
	(number < 0 ? (((s[i++] = '-') && (number *= -1))) : 0);
	k = number;
	while (k > 10)
	{
		s[i++] = k % 10 + 48;
		k /= 10;
	}
	s[i++] = k + 48;
	r_reversion(s);
	s[i++] = '.';
	while (prec-- > 0)
	{
		k = number;
		k *= 10;
		number = number * 10 - k;
		k = number;
		s[i++] = k + 48;
	}
	return (round(s, i, k, number));
}
