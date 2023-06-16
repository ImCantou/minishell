/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <qcherel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:39:31 by qcherel           #+#    #+#             */
/*   Updated: 2022/05/18 18:18:46 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	print_fading_minishell(void);

void	handler(int signum)
{
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		shell()->status = 130;
		print_fading_minishell();
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

struct s_mainargs	*main_args(int ac, char **av, char **envp)
{
	struct s_mainargs	*ptr;

	ptr = malloc(sizeof(struct s_mainargs));
	ptr->ac = ac;
	ptr->av = av;
	ptr->envp = envp;
	return (ptr);
}

//	printf("\e[1m\e[38;5;82mM\e[38;5;118mi\e[38;5;121mn\e[38;5;121mi
//	\e[38;5;159ms\e[38;5;86mh\e[38;5;44me\e[38;5;74ml\e[38;5;69ml\e[38;5;7m ");

void	print_fading_minishell(void)
{
	printf("\e[1m\e[38;5;82mM");
	printf("\e[38;5;118mi");
	printf("\e[38;5;121mn");
	printf("\e[38;5;121mi");
	printf("\e[38;5;159ms");
	printf("\e[38;5;86mh");
	printf("\e[38;5;44me");
	printf("\e[38;5;74ml");
	printf("\e[38;5;69ml");
	printf("\e[38;5;7m ");
}

int	main(int ac, char **av, char **envp)
{
	char	*ret;
	t_shell	*p_shell;

	ret = NULL;
	p_shell = shell();
	p_shell->env = create_envlist(envp);
	p_shell->margs = main_args(ac, av, envp);
	while (1)
	{
		signal(SIGINT, handler);
		signal(SIGQUIT, SIG_IGN);
		if (ret)
			free(ret);
		print_fading_minishell();
		ret = readline("$> \e[0m");
		if (ret)
		{
			if (ret[0])
				add_history(ret);
			minishell(ret);
		}
		else
			ft_exit(NULL);
	}
}
