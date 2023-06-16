/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:35:49 by qcherel           #+#    #+#             */
/*   Updated: 2021/11/25 10:05:09 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;

	i = ft_strlen(dst);
	j = ft_strlen(src);
	k = 0;
	l = i;
	if (size <= i)
		return (j + size);
	while ((l < size - 1) && (src[k] != 0))
		dst[l++] = src[k++];
	dst[l] = 0;
	return (i + j);
}
