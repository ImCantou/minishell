/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <qcherel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:54:42 by qcherel           #+#    #+#             */
/*   Updated: 2022/05/09 14:59:36 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../Includes/perror_exit.h"
#include "../Includes/minishell.h"

void	pwd_update(t_keylist *oldpwd, t_keylist *pwd, char *newpwd)
{
	if (!oldpwd && !pwd)
	{
		add_to_env2(&shell()->env, "PWD", newpwd);
		add_to_env2(&shell()->env, "OLDPWD", NULL);
	}
	else if (!oldpwd)
	{
		add_to_env2(&shell()->env, "OLDPWD", pwd->value);
		pwd->value = newpwd;
	}
	else if (!pwd)
	{
		free(oldpwd->value);
		oldpwd->value = NULL;
		add_to_env2(&shell()->env, "PWD", newpwd);
	}
	else
	{
		free(oldpwd->value);
		oldpwd->value = pwd->value;
		pwd->value = newpwd;
	}
}

void	change_pwd_in_env(t_keylist **begin)
{
	char		currpwd[PATH_MAX];
	t_keylist	*envl;
	t_keylist	*pwd;
	t_keylist	*oldpwd;

	envl = *begin;
	pwd = NULL;
	oldpwd = NULL;
	while (envl)
	{
		if (!ft_strcmp(envl->key, "PWD"))
			pwd = envl;
		else if (!ft_strcmp(envl->key, "OLDPWD"))
			oldpwd = envl;
		envl = envl->next;
	}
	pwd_update(oldpwd, pwd, ft_strdup(getcwd(currpwd, sizeof(currpwd))));
}

int	_cd(char **args)
{
	if (!args[1])
	{
		if (!scan_env("HOME", &shell()->env))
		{
			write(2, "cd: HOME is unset\n", 18);
			return (1);
		}
		else if (chdir(scan_env("HOME", &shell()->env)))
		{
			perror("cd: ");
			return (1);
		}
	}
	else if (args[1] && args[2])
	{
		write(2, "cd: too many arguments\n", 23);
		return (1);
	}
	else if (chdir(args[1]))
	{
		perror("cd: ");
		return (1);
	}
	change_pwd_in_env(&shell()->env);
	return (0);
}
