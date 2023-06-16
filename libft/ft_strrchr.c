/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:03:03 by qcherel           #+#    #+#             */
/*   Updated: 2021/11/30 15:24:19 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s2;
	int		l;
	char	cc;

	cc = (char)c;
	l = ft_strlen(s);
	s2 = (char *)s;
	while (l >= 0)
	{
		if (s[l] == cc)
			return (s2 + l);
		l--;
	}
	return (0);
}
