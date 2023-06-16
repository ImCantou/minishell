/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <qcherel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:55:58 by qcherel           #+#    #+#             */
/*   Updated: 2022/05/18 16:56:42 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

t_shell	*shellinit(void)
{
	t_shell	*shell;

	shell = malloc(sizeof(t_shell));
	shell->env = NULL;
	shell->margs = NULL;
	shell->status = 0;
	return (shell);
}

t_shell	*shell(void)
{
	static t_shell	*shell;
	static int		status;

	if (status == 0)
	{
		shell = shellinit();
		status = 1;
	}
	return (shell);
}

void	catchsignal(int status)
{
	if (WTERMSIG(status) == SIGINT)
	{
		shell()->status = 130;
		write(1, "\n", 1);
	}
	else if (WTERMSIG(status) == SIGQUIT)
	{
		shell()->status = 131;
		write(1, "Quit (CORE Dumped)\n", 19);
	}
}

int	nextstrs(char ***lol, int i)
{
	int	ret;

	ret = 0;
	while (lol[++i])
		ret++;
	return (ret);
}

int	minishell(char *str)
{
	char	***lol;
	int		i;

	i = -1;
	if (!str[0])
		return (shell()->status);
	lol = NULL;
	lol = simple_cmd_cut(firstlexer(str));
	while (lol && lol[++i])
	{
		lol[i] = do_expansion(lol[i]);
		if (!lol[i])
		{
			while (--i >= 0)
				free(lol[i]);
			free(lol);
			return (0);
		}
	}
	i = -1;
	if (lol)
		exec(lol);
	freetest(lol, 1);
	return (0);
}
