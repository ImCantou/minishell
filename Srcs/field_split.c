/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <qcherel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:03:04 by lheurtev          #+#    #+#             */
/*   Updated: 2022/05/18 14:19:45 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

static int	ft_sep(char *charset, char *str, int i)
{
	int	j;

	j = 0;
	while (charset[j])
	{
		if (str[i] == charset[j] && is_unquoted(str, i, 0))
			return (1);
		j++;
	}
	return (0);
}

static int	ft_count_word(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_sep(charset, str, i) == 0
			&& (ft_sep(charset, str, i + 1) || str[i + 1] == 0))
			count++;
		i++;
	}
	return (count);
}

static char	*ft_word_in_tab(char *str, int *i, char *charset)
{
	char	*word;
	int		j;

	j = 0;
	while (ft_sep(charset, str, *i) && str[*i])
		*i = *i + 1;
	while (str[*i + j] && ft_sep(charset, str, *i + j) == 0)
		j++;
	word = (char *) malloc(sizeof(char) * (j + 1));
	j = 0;
	while (str[*i + j] && ft_sep(charset, str, *i + j) == 0)
	{
		word[j] = str[*i + j];
		j++;
	}
	word[j] = 0;
	*i = *i + j;
	return (word);
}

char	**splitcharset(char *str, char *charset)
{
	char	**tab_word;
	int		j;
	int		i;
	int		size;

	i = 0;
	j = 0;
	tab_word = NULL;
	size = ft_count_word(str, charset);
	if (size > 0)
		tab_word = malloc(sizeof(char *) * (size + 1));
	if (!tab_word)
		return (NULL);
	while (j < size)
	{
		tab_word[j] = ft_word_in_tab(str, &i, charset);
		j++;
	}
	tab_word[size] = 0;
	return (tab_word);
}

char	**field_split(char *s)
{
	char	**tmp;
	char	*charset;

	charset = NULL;
	if (!s)
		return (NULL);
	charset = scan_env("IFS", &shell()->env);
	if (!charset || charset[0] == 0)
	{
		charset = ft_strdup(" \t\n");
		tmp = splitcharset(s, charset);
		free(charset);
	}
	else
	{
		tmp = splitcharset(s, charset);
	}
	return (tmp);
}
