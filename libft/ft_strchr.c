/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:52:51 by qcherel           #+#    #+#             */
/*   Updated: 2021/11/30 15:24:00 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*cs;
	char	cc;

	cc = (char)c;
	i = 0;
	cs = (char *)s;
	while (s[i])
	{
		if (s[i] == cc)
			return (cs + i);
		i++;
	}
	if (cc == 0)
		return (cs + i);
	return (0);
}
