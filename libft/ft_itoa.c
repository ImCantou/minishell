/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:09:37 by qcherel           #+#    #+#             */
/*   Updated: 2021/11/25 10:09:31 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_grand(int n, int *i)
{
	char	*tab;
	int		neg;

	neg = 0;
	if (n < 0)
		neg = 1;
	else if (n == 0)
		*i = 1;
	while (n != 0)
	{
		*i += 1;
		n /= 10;
	}
	tab = malloc(sizeof(char) * (*i + 1 + neg));
	if (!tab)
		return (0);
	return (tab);
}

static void	ft_fillstr(char *s, int i, int n)
{
	long	ln;

	ln = n;
	if (n < 0)
	{
		s[0] = '-';
		ln *= -1;
	}
	if (ln >= 10)
	{
		ft_fillstr(s, i - 1, ln / 10);
	}
	s[i] = (ln % 10) + '0';
}

char	*ft_itoa(int n)
{
	char	*s;
	int		i;

	i = 0;
	s = ft_grand(n, &i);
	if (!s)
		return (0);
	if (n < 0)
	{
		s[i + 1] = 0;
		ft_fillstr(s, i, n);
	}
	else
	{
		s[i] = 0;
		ft_fillstr(s, i - 1, n);
	}
	return (s);
}
