/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_max_itoa.base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskostyl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 00:50:08 by kskostyl          #+#    #+#             */
/*   Updated: 2019/07/30 02:30:24 by kskostyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*u_max_itoa_base_reversion(char *s)
{
	int		i;
	int		l;

	i = 0;
	l = ft_strlen(s);
	while (i < --l)
	{
		s[i] = s[i] ^ s[l];
		s[l] = s[i] ^ s[l];
		s[i] = s[i] ^ s[l];
		i++;
	}
	return (s);
}

char			*u_max_itoa_base(uintmax_t number, uintmax_t base, int flag)
{
	char	*s;
	int		i;

	i = 0;
	s = ft_memalloc(21);
	while (number > (base - 1))
	{
		if (number % base < 10)
		{
			s[i++] = number % base + 48;
			number /= base;
		}
		else
		{
			s[i++] = (flag == 1 ? number %
					base + 65 - 10 : number % base + 97 - 10);
			number /= base;
		}
	}
	if (number < 10)
		s[i] = number + 48;
	else
		s[i] = (flag == 1 ? number + 65 - 10 : number + 97 - 10);
	return (u_max_itoa_base_reversion(s));
}
