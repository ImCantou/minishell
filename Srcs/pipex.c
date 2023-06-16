/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <qcherel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:20:56 by lheurtev          #+#    #+#             */
/*   Updated: 2022/05/18 18:01:26 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	sigfct(int pid)
{
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
	}
	else
		signal(SIGINT, SIG_IGN);
}

void	closetab(int **tab, int len)
{
	int	i;

	i = -1;
	while (++i < len)
	{
		close(tab[i][0]);
		close(tab[i][1]);
	}
}

int	**createpipetab(int len)
{
	int	i;
	int	**tab;

	i = -1;
	tab = malloc(sizeof(int *) * len);
	if (!tab)
		return (NULL);
	while (++i < len)
	{
		tab[i] = malloc(sizeof(int) * 2);
		if (!tab[i])
			return (NULL);
		pipe(tab[i]);
	}
	return (tab);
}

int	pipex(char ***s, t_pipeline *execpipe, int i)
{
	char	**ret;

	if (i != 0)
		dup2(execpipe->pipetab[i - 1][0], STDIN_FILENO);
	if (i != execpipe->len - 1)
		dup2(execpipe->pipetab[i][1], STDOUT_FILENO);
	closetab(execpipe->pipetab, execpipe->len);
	ret = redfct(s, execpipe, i, 0);
	if (!ret)
		return (1);
	if (is_builtin(ret[0], -1, -1) == 0)
		execbuiltin(ret[0], s, i, execpipe);
	else if (!perror_executable(ret[0]))
		execve(ret[0], ret, envl_to_envp(&shell()->env));
	freetest(s, 0);
	freepipetab(execpipe->pipetab, execpipe->len);
	return (0);
}
