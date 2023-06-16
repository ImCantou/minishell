/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:01:38 by qcherel           #+#    #+#             */
/*   Updated: 2021/11/26 18:22:19 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			len;
	char			*ns;

	if (!s)
		return (0);
	i = 0;
	len = ft_strlen(s);
	ns = malloc(sizeof(char) * (len + 1));
	if (!ns)
		return (0);
	while (i < len)
	{
		ns[i] = (*f)(i, s[i]);
		i++;
	}
	ns[i] = 0;
	return (ns);
}
