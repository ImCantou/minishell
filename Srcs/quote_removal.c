/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_removal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <qcherel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:55:16 by qcherel           #+#    #+#             */
/*   Updated: 2022/05/09 14:55:13 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

char	*strdup_qrm(char *s, int a, int b)
{
	char	*dup;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	dup = malloc(sizeof(char) * i + 1 - 2);
	if (!dup)
		return (0);
	i = 0;
	while (s[i + (i >= a) + (i + (i >= a) >= b)])
	{
		dup[i] = s[i + (i >= a) + (i + (i >= a) >= b)];
		i++;
	}
	dup[i] = 0;
	free(s);
	return (dup);
}

char	*progress_qremove(char *str, int *index, char c)
{
	int		a;
	int		i;

	a = *index;
	i = -1;
	while (str && str[++i])
	{
		if (i > *index && str[i] == c)
		{
			*index = i - 2;
			return (strdup_qrm(str, a, i));
		}
	}
	if (c == '"')
		write(2, "Minishell: missing closing quote near `\"`\n", 43);
	else if (c == 39)
		write(2, "Minishell: missing closing quote near `'`\n", 43);
	if (str)
		free(str);
	return (NULL);
}

char	*quote_remove(char *str)
{
	char	*ret;
	int		i;

	i = -1;
	ret = str;
	while (ret && ret[++i])
	{
		if (ret[i] == '"' || ret[i] == 39)
			ret = progress_qremove(ret, &i, ret[i]);
	}
	return (ret);
}

char	**doquote_removal(char **strs)
{
	int	i;

	i = -1;
	while (strs && strs[++i])
	{
		strs[i] = quote_remove(strs[i]);
		if (!strs[i])
		{
			errorspl(strs);
			return (NULL);
		}
	}
	return (strs);
}
