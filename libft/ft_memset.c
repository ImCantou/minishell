/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:10:03 by qcherel           #+#    #+#             */
/*   Updated: 2021/11/25 10:17:50 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	t;
	char	*cs;

	t = 0;
	cs = (char *)s;
	while (t < n)
	{
		cs[t] = c;
		t++;
	}
	return (s);
}
