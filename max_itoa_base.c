/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_itoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskostyl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 01:01:58 by kskostyl          #+#    #+#             */
/*   Updated: 2019/07/30 02:21:29 by kskostyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*max_itoa_base_reversion(char *s)
{
	int		i;
	int		len_gth;

	i = 0;
	len_gth = ft_strlen(s);
	if (s[i] == '-')
		i++;
	while (i < --len_gth)
	{
		s[i] = s[i] ^ s[len_gth];
		s[len_gth] = s[i] ^ s[len_gth];
		s[i] = s[i] ^ s[len_gth];
		i++;
	}
	return (s);
}

char			*max_itoa_base(intmax_t number, uintmax_t ba_se, int flags)
{
	char		*s;
	int			i;
	uintmax_t	k;

	i = 0;
	s = ft_memalloc(21);
	(number < 0 ? ((s[i++] = '-') && (number *= -1)) : 0);
	k = number;
	while (k > (ba_se - 1))
		if (k % ba_se < 10)
		{
			s[i++] = k % ba_se + 48;
			k /= ba_se;
		}
		else
		{
			s[i++] = (flags == 1 ? k % ba_se + 65 - 10 : k % ba_se + 97 - 10);
			k /= ba_se;
		}
	if (k < 10)
		s[i] = k + 48;
	else
		s[i] = (flags == 1 ? k + 65 - 10 : k + 97 - 10);
	return (max_itoa_base_reversion(s));
}
