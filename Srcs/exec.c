/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <qcherel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 11:36:44 by lheurtev          #+#    #+#             */
/*   Updated: 2022/05/18 18:18:26 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	execfct(char ***s)
{
	int			i;
	int			pid;
	int			status;
	t_pipeline	execpipe;

	status = 0;
	signal(SIGQUIT, SIG_DFL);
	execpipe.len = ft_hslen(s);
	i = -1;
	execpipe.pipetab = createpipetab(execpipe.len);
	if (!execpipe.pipetab)
		exit(12);
	while (++i < execpipe.len)
	{
		pid = fork();
		if (pid == 0)
			exit(pipex(s, &execpipe, i));
	}
	freetest(s, 0);
	closetab(execpipe.pipetab, execpipe.len);
	freepipetab(execpipe.pipetab, execpipe.len);
	while (i-- > 0)
		waitpid(-1, &status, 0);
	exit(WEXITSTATUS(status));
}

void	execnobuiltin(char ***s)
{
	int	pid;
	int	status;

	pid = fork();
	sigfct(pid);
	if (pid == 0)
		execve(s[0][0], s[0], envl_to_envp(&shell()->env));
	waitpid(pid, &status, 0);
	shell()->status = WEXITSTATUS(status);
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

int	execone(char ***s, char **tabfile)
{
	int		savedstdin;
	int		savedstdout;
	char	**ret;
	int		*lol;

	lol = &shell()->status;
	savedstdin = dup(STDIN_FILENO);
	savedstdout = dup(STDOUT_FILENO);
	signal(SIGINT, exechandler);
	if (!parsexec(s, tabfile, 0))
	{
		signal(SIGQUIT, exechandler);
		ret = redfct(s, NULL, 0, 1);
		if (!ret)
		{
			shell()->status = 1;
			return (dupnclose(savedstdin, savedstdout, 1));
		}
		if (!is_builtin(ret[0], savedstdin, savedstdout))
			*lol = execbuiltin(ret[0], s, 0, NULL);
		else if (!perror_executable(ret[0]))
			execnobuiltin(s);
	}
	return (dupnclose(savedstdin, savedstdout, 0));
}

void	multexec(char ***s, char **tabfile)
{
	int	status;
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		if (!parsexec(s, tabfile, 1))
		{
			ft_megafree(tabfile, 1);
			execfct(s);
		}
		freetest(s, 0);
		exit(0);
	}
	waitpid(pid, &status, 0);
	shell()->status = WEXITSTATUS(status);
	catchsignal(status);
}

int	exec(char ***s)
{
	char	**tabfile;
	char	*tmpfile;

	if (!s)
		return (1);
	tmpfile = NULL;
	tabfile = createtabfile(s, tmpfile);
	if (ft_hslen(s) == 1)
		execone(s, tabfile);
	else
	{
		signal(SIGINT, SIG_IGN);
		multexec(s, tabfile);
	}
	signal(SIGINT, handler);
	ft_megafree(tabfile, 0);
	return (0);
}
