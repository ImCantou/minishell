/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exectools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheurtev <lheurtev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:19:14 by lheurtev          #+#    #+#             */
/*   Updated: 2022/05/17 15:36:09 by lheurtev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	exechandler(int signum)
{
	if (signum == SIGINT)
	{
		printf("\n");
		close(STDIN_FILENO);
		shell()->status = 130;
	}
	if (signum == SIGQUIT)
	{
		shell()->status = 131;
	}
}

void	freetest(char ***lol, int mode)
{
	int	i;
	int	j;

	i = -1;
	while (lol && lol[++i])
	{
		j = -1;
		while (lol[i][++j])
			free(lol[i][j]);
		free(lol[i]);
	}
	if (lol)
		free(lol);
	if (!mode)
	{
		free_keylist(&shell()->env);
		free(shell()->margs);
		free(shell());
		rl_clear_history();
	}
}

void	freepipetab(int **tab, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		free(tab[i]);
	free(tab);
}

int	execbuiltin(char *str, char ***s, int i, t_pipeline *pipe)
{
	if (ft_strcmp(str, "cd") == 0)
		return (_cd(s[i]));
	if (ft_strcmp(str, "echo") == 0)
		return (_echo(s[i]));
	if (ft_strcmp(str, "env") == 0)
		return (_env(s[i]));
	if (ft_strcmp(str, "exit") == 0)
		return (exitfonction(s, i, pipe));
	if (ft_strcmp(str, "export") == 0)
		return (_export(s[i]));
	if (ft_strcmp(str, "pwd") == 0)
		return (_pwd(s[i]));
	if (ft_strcmp(str, "unset") == 0)
		return (_unset(s[i]));
	return (1);
}

int	dupnclose(int in, int out, int ret)
{
	dup2(in, STDIN_FILENO);
	dup2(out, STDOUT_FILENO);
	close(in);
	close(out);
	return (ret);
}
