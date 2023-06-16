/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheurtev <lheurtev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:37:22 by qcherel           #+#    #+#             */
/*   Updated: 2022/05/19 14:21:36 by lheurtev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"
#include "../Includes/perror_exit.h"
#include "../libft/libft.h"

int	check_param_format_is_nb(char *param)
{
	int	i;

	i = -1;
	if (!param)
		return (0);
	if (ft_atoi(param) != ft_atol(param))
		return (1);
	if (param[0] == '-' || param[0] == '+')
		i++;
	while (param[++i])
	{
		if ((param[i] > '9' || param[i] < '0'))
		{
			return (1);
		}
	}
	return (0);
}

int	ft_exit(char *n)
{
	int	exitreturn;

	write(2, "exit\n", 5);
	if (check_param_format_is_nb(n))
	{
		write(2, "Invalid format of argument for \"exit\".\n", 39);
		return (2);
	}
	if (n)
		exitreturn = ft_atoi(n);
	else
		exitreturn = shell()->status;
	free_keylist(&shell()->env);
	free(shell()->margs);
	free(shell());
	rl_clear_history();
	if (n)
		free(n);
	exit(exitreturn);
	return (exitreturn);
}

int	bi_exit(char **args)
{
	char	*arg;
	int		i;

	if (!args || !args[0])
		return (127);
	if (args[1] && args[2])
	{
		write(1, "exit\n", 5);
		write(1, "minishell: exit: too many arguments\n", 36);
		return (1);
	}
	arg = ft_strdup(args[1]);
	i = -1;
	while (args[++i])
		free(args[i]);
	free(args);
	return (ft_exit(arg));
}

char	**freeexit(char ***s, int i)
{
	int		j;
	int		k;
	char	**ret;

	j = -1;
	while (s[++j])
	{
		if (j == i)
			ret = s[j];
		else
		{
			k = -1;
			while (s[j][++k])
				free(s[j][k]);
			free(s[j]);
		}
	}
	free(s);
	return (ret);
}

int	exitfonction(char ***s, int i, t_pipeline *pipe)
{
	char	**arg;

	if (ft_superstrlen(s[i]) >= 3)
	{
		write(2, "exit\n", 5);
		write(2, "minishell: exit: too many arguments\n", 36);
		return (1);
	}
	if (!check_param_format_is_nb(s[i][1]))
	{
		arg = freeexit(s, i);
		if (pipe)
			freepipetab(pipe->pipetab, pipe->len);
		return (bi_exit(arg));
	}
	else
	{
		write(2, "exit\n", 5);
		if (ft_atoi(s[i][1]) != ft_atol(s[i][1]))
			write(2, "Argument overflow numeric value.\n", 33);
		else
			write(2, "Invalid format of argument for \"exit\".\n", 39);
		return (2);
	}
}
