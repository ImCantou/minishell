/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <qcherel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:55:17 by qcherel           #+#    #+#             */
/*   Updated: 2022/05/18 16:42:43 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	delete_env_entry(t_keylist **begin, char *mykey)
{
	t_keylist	*env;
	t_keylist	*tmp;

	env = *begin;
	while (env)
	{
		if (!ft_strcmp(mykey, env->key))
		{
			tmp->next = env->next;
			free(env->key);
			if (env->value)
				free(env->value);
			if (env == *begin)
			{	
				free(env);
				*begin = NULL;
			}
			else
				free(env);
			return ;
		}
		tmp = env;
		env = env->next;
	}
}

int	_unset(char **args)
{
	int	i;

	if (!args || !args[0])
		return (127);
	i = 0;
	while (args[++i])
	{
		if (scan_env(args[i], &shell()->env))
			delete_env_entry(&shell()->env, args[i]);
	}
	return (0);
}
