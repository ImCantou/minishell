/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <qcherel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:44:48 by qcherel           #+#    #+#             */
/*   Updated: 2022/05/09 14:58:23 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/perror_exit.h"
#include "../Includes/minishell.h"

int	_env(char **env)
{
	t_keylist	*envl;

	if (!env)
		return (127);
	if (env[0] && env[1])
	{
		write(2, "env: too many arguments\n", 24);
		return (1);
	}
	envl = shell()->env;
	while (envl)
	{
		if (envl->key && envl->value)
		{
			write(1, envl->key, ft_strlen(envl->key));
			write(1, "=", 1);
			write(1, envl->value, ft_strlen(envl->value));
			write(1, "\n", 1);
		}
		envl = envl->next;
	}
	return (0);
}
