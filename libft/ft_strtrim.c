/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:02:54 by qcherel           #+#    #+#             */
/*   Updated: 2021/11/26 18:13:29 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_checkset(char c, const char *set)
{
	int	i;

	i = 0;
	while (c != set[i] && set[i])
		i++;
	if (set[i])
		return (0);
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tstr;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!s1)
		return (0);
	while (s1[i] && !ft_checkset(s1[i], set))
		i++;
	k = ft_strlen(s1);
	while (k >= 0 && !ft_checkset(s1[k - 1], set) && i != k)
		k--;
	tstr = malloc(sizeof(char) * (k - i + 1));
	if (!tstr)
		return (NULL);
	while (i + j < k)
	{
		tstr[j] = s1[i + j];
		j++;
	}
	tstr[j] = 0;
	return (tstr);
}
