/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheurtev <lheurtev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:12:48 by lheurtev          #+#    #+#             */
/*   Updated: 2022/05/19 14:32:29 by lheurtev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"
#include "../Includes/parsing.h"

char	**newword(char **final, int *x, int *j, int *wordortoken)
{
	*wordortoken *= -1;
	final[*j][*x] = 0;
	final = ft_realloc(final, ft_superstrlen(final) + 1, sizeof(char *), 2);
	final[*j + 2] = NULL;
	*j += 1;
	*x = 0;
	return (final);
}

int	parstest(int wordortoken, int x, char c, char c1)
{
	if (wordortoken < 0 && checktoken(c) && x > 1)
	{
		write(2, "syntax error near unexpected token '", 37);
		write(2, &c, 1);
		write(2, "'\n", 2);
		return (0);
	}
	else if (wordortoken < 0 && checktoken(c) && x >= 1
		&& specialchecker(c, c1))
	{
		write(2, "syntax error near unexpected token '", 37);
		write(2, &c, 1);
		write(2, "'\n", 2);
		return (0);
	}
	return (1);
}

void	initvar(int *i, int *wordortoken, int *x, int *j)
{
	*i = -1;
	*j = 0;
	*x = 0;
	*wordortoken = 1;
}

char	**lexingfct(char *str, char **final)
{
	int	i;
	int	wordortoken;
	int	j;
	int	x;

	initvar(&i, &wordortoken, &x, &j);
	if (checktoken(str[0]))
		wordortoken *= -1;
	while (str[++i])
	{
		if (wordortoken > 0 && is_unquoted(str, i, 0) && checktoken(str[i]))
			final = newword(final, &x, &j, &wordortoken);
		if (i > 0 && !parstest(wordortoken, x, str[i], str[i - 1]))
			return (free_final(final));
		if (wordortoken < 0 && !checktoken(str[i]) && str[i])
			final = newword(final, &x, &j, &wordortoken);
		final[j] = ft_realloc(final[j], ft_strlen(final[j]), sizeof(char), 2);
		final[j][x] = str[i];
		final[j][x + 1] = 0;
		x++;
	}
	final[j][x] = 0;
	final[j + 1] = 0;
	return (final);
}

char	**firstlexer(char *str)
{
	char	**final;

	if (!str)
		return (NULL);
	final = malloc(sizeof(char *) * 2);
	if (!final)
		return (NULL);
	final[0] = NULL;
	final[1] = NULL;
	return (lexingfct(str, final));
}
