/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <qcherel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:56:55 by qcherel           #+#    #+#             */
/*   Updated: 2022/05/05 12:19:32 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	**ft_splinsert(char **spl1, char **spl2, int *index)
{
	int		i;
	int		j;
	char	**ret;

	ret = malloc(sizeof(char *) * (ft_spllen(spl1) + ft_spllen(spl2) + 1));
	j = -1;
	i = -1;
	if (!ret)
		return (NULL);
	while (spl1 && ++i < *index)
		ret[i] = spl1[i];
	while (spl2 && spl2[++j])
		ret[i + j] = spl2[j];
	j--;
	while (spl1 && spl1[++i])
		ret[i + j] = spl1[i];
	ret[i + j] = 0;
	free(spl2);
	return (ret);
}
