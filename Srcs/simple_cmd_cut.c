/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd_cut.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <qcherel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:37:21 by qcherel           #+#    #+#             */
/*   Updated: 2022/05/09 15:08:10 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../Includes/minishell.h"

char	**cpy_spl(char **spl, int a, int b)
{
	char	**newspl;
	int		i;

	i = -1;
	newspl = malloc(sizeof(char *) * ((b - a) + 1));
	if (!newspl)
		return (NULL);
	while (a < b)
	{
		newspl[++i] = spl[a];
		a++;
	}
	newspl[++i] = NULL;
	return (newspl);
}

char	***free_token(char ***ret, char **ptrfree)
{
	if (ptrfree)
		free(ptrfree);
	return (ret);
}

int	is_a_token(char *str, int mode)
{
	int	i;

	i = -1;
	if (!ft_strcmp(str, "|") && (mode == ALL_TOKENS || mode == PIPE_TOKEN))
		return (1);
	else if ((!ft_strcmp(str, ">>") || !ft_strcmp(str, "<<")
			|| !ft_strcmp(str, ">") || !ft_strcmp(str, "<"))
		&& (mode == ALL_TOKENS || mode == REDIR_TOKEN))
	{
		return (1);
	}
	while (str[++i])
	{
		if (str[i] != ' ')
			return (0);
	}
	return (1);
}

char	**token_checker(char **tokens)
{
	int	i;

	i = -1;
	tokens = clear_blankstr(tokens);
	while (tokens && tokens[++i])
	{
		if (is_a_token(tokens[i], PIPE_TOKEN)
			&& (i == 0 || !tokens[i + 1]))
		{
			parseerrornear(tokens[i]);
			errorspl(tokens);
			return (NULL);
		}
		else if ((is_a_token(tokens[i], ALL_TOKENS)
				&& (!tokens[i + 1] || is_a_token(tokens[i + 1], PIPE_TOKEN)))
			|| (is_a_token(tokens[i], REDIR_TOKEN)
				&& is_a_token(tokens[i + 1], ALL_TOKENS)))
		{
			parseerrornear(tokens[i]);
			errorspl(tokens);
			return (NULL);
		}	
	}
	return (tokens);
}

char	***simple_cmd_cut(char **token_recognition)
{
	char	***cmds;
	char	**curr_cmd;
	int		i;
	int		j;
	int		nb;

	i = -1;
	j = 1;
	nb = -1;
	cmds = NULL;
	token_recognition = token_checker(token_recognition);
	while (token_recognition && token_recognition[++i])
	{
		while (token_recognition[j] && ft_strcmp(token_recognition[j], "|"))
			j++;
		curr_cmd = cpy_spl(token_recognition, i, j);
		free(token_recognition[j]);
		cmds = ft_realloc(cmds, ++nb + 1, sizeof(char **), 1);
		cmds[nb] = curr_cmd;
		cmds[nb + 1] = NULL;
		i = j++;
		if (!token_recognition[i])
			i--;
	}
	return (free_token(cmds, token_recognition));
}
