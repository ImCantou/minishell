/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheurtev <lheurtev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:20:33 by lheurtev          #+#    #+#             */
/*   Updated: 2022/03/15 11:51:42 by lheurtev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	checktoken(char c)
{
	if (c == '|' || c == '>' || c == '<' || c == '&' || c == ';')
		return (1);
	return (0);
}

char	**free_final(char **final)
{
	int	i;

	i = -1;
	while (final[++i])
		free(final[i]);
	free(final);
	return (NULL);
}

int	ft_superstrlen(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	specialchecker(char c, char c1)
{
	if (c != c1)
	{
		if ((c1 == '<' || c1 == '>') && (c == '&' || c == '>'))
			return (0);
		else if (c1 == '>' && c == '|')
			return (0);
		return (1);
	}
	return (0);
}
