/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheurtev <lheurtev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:51:16 by lheurtev          #+#    #+#             */
/*   Updated: 2022/03/15 15:20:00 by lheurtev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, int ptrsize, int size, int add)
{
	char	*tmp;

	tmp = malloc(size * (ptrsize + add));
	if (!tmp)
		return (NULL);
	if (!ptr)
		return (tmp);
	tmp = ft_memcpy(tmp, ptr, ptrsize * size);
	free(ptr);
	return (tmp);
}
