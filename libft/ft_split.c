/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:44:36 by qcherel           #+#    #+#             */
/*   Updated: 2021/11/26 18:37:42 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_count_word(char const *s, char ***tab_word, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c
			&& (s[i + 1] == c || s[i + 1] == 0))
			count++;
		i++;
	}
	*tab_word = (char **) malloc(sizeof(char *) * (count + 1));
	if (!(*tab_word))
		return (0);
	return (count);
}

static char	*ft_word_in_tab(char const *s, int *i, char c)
{
	char	*word;
	int		j;

	j = 0;
	while (s[*i] == c && s[*i])
		*i = *i + 1;
	while (s[*i + j] && c != s[*i + j])
		j++;
	word = (char *) malloc(sizeof(char) * (j + 1));
	j = 0;
	while (s[*i + j] && s[*i + j] != c)
	{
		word[j] = s[*i + j];
		j++;
	}
	word[j] = 0;
	*i = *i + j;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**tab_word;
	int		j;
	int		i;
	int		size;

	if (!s)
		return (0);
	i = 0;
	j = 0;
	size = ft_count_word(s, &tab_word, c);
	if (!tab_word)
		return (NULL);
	while (j < size)
	{
		tab_word[j] = ft_word_in_tab(s, &i, c);
		j++;
	}
	tab_word[size] = 0;
	return (tab_word);
}
