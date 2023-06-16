/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitcharset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheurtev <lheurtev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:18:00 by lheurtev          #+#    #+#             */
/*   Updated: 2022/03/15 15:23:09 by lheurtev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

static int	ft_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_count_word(char *str, char ***tab_word, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_sep(str[i], charset) == 0
			&& (ft_sep(str[i + 1], charset) || str[i + 1] == 0))
			count++;
		i++;
	}
	*tab_word = (char **) malloc(sizeof(char *) * (count + 1));
	if (sizeof(*tab_word) == 0)
		return (0);
	return (count);
}

static char	*ft_word_in_tab(char *str, int *i, char *charset)
{
	char	*word;
	int		j;

	j = 0;
	while (ft_sep(str[*i], charset) && str[*i])
		*i = *i + 1;
	while (str[*i + j] && ft_sep(str[*i + j], charset) == 0)
		j++;
	word = (char *) malloc(sizeof(char) * (j + 1));
	j = 0;
	while (str[*i + j] && ft_sep(str[*i + j], charset) == 0)
	{
		word[j] = str[*i + j];
		j++;
	}
	word[j] = 0;
	*i = *i + j;
	return (word);
}

char	**ft_splitcharset(char *str, char *charset)
{
	char	**tab_word;
	int		j;
	int		i;
	int		size;

	i = 0;
	j = 0;
	size = ft_count_word(str, &tab_word, charset);
	if (size > 0)
		tab_word = malloc(sizeof(char *) * (size + 1));
	while (j < size)
	{
		tab_word[j] = ft_word_in_tab(str, &i, charset);
		j++;
	}
	tab_word[size] = 0;
	return (tab_word);
}
