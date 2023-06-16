/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:31:41 by qcherel           #+#    #+#             */
/*   Updated: 2021/11/26 17:36:31 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*nstr;
	unsigned int	slen;

	i = 0;
	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		nstr = malloc(sizeof(char));
	else if (slen - start < len)
		nstr = malloc(sizeof(char) * (slen - start + 1));
	else
		nstr = malloc(sizeof(char) * (len + 1));
	if (!nstr)
		return (0);
	i = 0;
	while (s[i + start] && i < len && start + i < slen)
	{
		nstr[i] = s[i + start];
		i++;
	}
	nstr[i] = 0;
	return (nstr);
}
