/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:04:47 by qcherel           #+#    #+#             */
/*   Updated: 2021/11/26 18:00:04 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*cdest;
	const char	*csrc = (const char *)src;

	cdest = (char *)dest;
	if (!src && !dest)
		return (NULL);
	if (src > dest)
	{
		i = -1;
		while (++i < n)
			cdest[i] = csrc[i];
	}
	else
	{
		i = 0;
		while (n - i > 0)
		{
			i++;
			cdest[n - i] = csrc[n - i];
		}
	}
	return (dest);
}
