/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:29:56 by qcherel           #+#    #+#             */
/*   Updated: 2021/11/25 10:04:53 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(src);
	if (i + 1 < size)
	{
		j = 0;
		while (j < i + 1)
		{
			dst[j] = src[j];
			j++;
		}
	}
	else if (size != 0)
	{
		j = 0;
		while (j < size - 1)
		{
			dst[j] = src[j];
			j++;
		}
		dst[j] = 0;
	}
	return (i);
}
