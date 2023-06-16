/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spljoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <qcherel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:29:32 by qcherel           #+#    #+#             */
/*   Updated: 2022/05/13 15:38:30 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_spljoin(char **s1, char **s2)
{
	char	**s3;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	s3 = malloc(sizeof(char *) * (ft_spllen(s1) + ft_spllen(s2) + 1));
	if (!s3)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = 0;
	return (s3);
}
