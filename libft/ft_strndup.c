/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskostyl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 22:33:20 by kskostyl          #+#    #+#             */
/*   Updated: 2019/07/30 23:38:49 by kskostyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t len)
{
	char	*create;
	size_t	i;

	i = 0;
	if (!(create = (char *)ft_memalloc(len + 1)))
		return (NULL);
	while (i < len && s[i])
	{
		create[i] = s[i];
		i++;
	}
	create[i] = 0;
	return (create);
}
