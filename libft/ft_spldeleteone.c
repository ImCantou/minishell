/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spldeleteone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <qcherel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:57:01 by qcherel           #+#    #+#             */
/*   Updated: 2022/05/05 12:19:06 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_spldeleteone(char **strs, int index)
{
	int		i;
	char	**ret;

	i = 0;
	while (strs[i + (i >= index)])
		i++;
	if (i == 0)
	{
		free(strs);
		return (NULL);
	}
	ret = malloc(sizeof(char *) * (i + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (strs[i + (i >= index)])
	{
		ret[i] = strs[i + (i >= index)];
		i++;
	}
	ret[i] = 0;
	free(strs);
	return (ret);
}
