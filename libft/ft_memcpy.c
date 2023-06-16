/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheurtev <lheurtev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:39:41 by qcherel           #+#    #+#             */
/*   Updated: 2022/03/10 15:59:02 by lheurtev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		t;
	char		*cdest;
	const char	*csrc = (const char *)src;

	t = 0;
	cdest = (char *)dest;
	if (!csrc && !dest)
		return (0);
	while (t < n)
	{
		cdest[t] = csrc[t];
		t++;
	}
	return (dest);
}
