/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilde_exp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <qcherel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:51:30 by qcherel           #+#    #+#             */
/*   Updated: 2022/05/13 16:24:57 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

char	*replace_tilde(char *str, int i)
{
	char	*nstr;
	char	*tmp;
	int		j;

	j = -1;
	nstr = malloc(sizeof(char) * (i + 1));
	if (!nstr)
		return (NULL);
	while (++j < i)
		nstr[j] = str[j];
	nstr[j] = 0;
	tmp = ft_strjoin(nstr, "$HOME");
	free(nstr);
	nstr = ft_strjoin(tmp, str + i + 1);
	free(tmp);
	free(str);
	return (nstr);
}

int	tilde_exceptions(char *str, int i)
{
	char	f;

	f = 0;
	if (i == 0)
		return (1);
	while (--i >= 0)
	{
		if (str[i] == ' ')
			return (1);
		else if (f == 0 && str[i] == 39)
			f = 39;
		else if (f == 0 && str[i] == '"')
			f = '"';
		else if (f != 0 && str[i] == f)
			f = 0;
		else
			return (0);
	}
	return (1);
}

int	is_unquoted(char *str, int i, int f)
{
	int		j;
	char	c;

	j = -1;
	c = 0;
	while (str[++j])
	{
		if ((str[j] == '"' && c == '"') || (str[j] == 39 && c == 39))
			c = 0;
		else if (str[j] == '"' && c == 0)
			c = '"';
		else if (str[j] == 39 && c == 0)
			c = 39;
		if (j == i && (c == 0 || (c == '"' && f == 1)))
			return (1);
		else if (j == i)
			return (0);
	}
	return (0);
}

char	*tilde_exp(char *str)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = ft_strdup(str);
	if (!tmp)
		return (NULL);
	while (tmp[++i])
	{
		if (is_unquoted(tmp, i, 1) && tmp[i] == '~')
		{
			if (tmp[i + 1] && tmp[i + 1] == '~')
				i++;
			if (((!tmp[i + 1]) || tmp[i + 1] == ' ' || tmp[i + 1] == '/')
				&& tilde_exceptions(tmp, i))
				tmp = replace_tilde(tmp, i);
			if (!tmp)
				return (NULL);
		}
	}
	free(str);
	return (tmp);
}
