/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <qcherel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:22:26 by qcherel           #+#    #+#             */
/*   Updated: 2022/05/09 14:58:08 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	is_newkey(char *str, t_keylist **envl)
{
	t_keylist	*env;

	env = *envl;
	while (env)
	{
		if (!ft_strcmp(env->key, str))
			return (1);
		env = env->next;
	}
	return (0);
}

static void	replace_envvalue(t_keylist **begin, char *mykey, char *str)
{
	t_keylist	*env;

	env = *begin;
	while (env)
	{
		if (!ft_strcmp(mykey, env->key))
		{
			if (env->value)
				free(env->value);
			env->value = create_envvalue(str);
			return ;
		}
		env = env->next;
	}
}

int	parsing_export(char *str, char c)
{
	int	i;

	if (!str || !str[0])
		return (1);
	i = -1;
	while (str[++i] && (c == 0 || (c == '+' && str[i + 1])))
	{
		if (i == 0 && !(ft_isalpha(str[i]) || str[i] == '_'))
			return (1);
		else if (!(ft_isalnum(str[i]) || str[i] == '_'))
			return (1);
	}
	return (0);
}

int	_export(char **args)
{
	int		i;
	char	*str;
	int		ret;

	ret = 0;
	if (!args || !args[0])
		return (127);
	i = 0;
	while (args[++i])
	{
		str = create_envkey(args[i]);
		if (parsing_export(str, 0))
		{
			ret = 1;
			write(2, "export: '", 9);
			write(2, args[i], ft_strlen(args[i]));
			write(2, "': not a valid identifier\n", 26);
		}
		else if (!is_newkey(str, &shell()->env))
			add_to_env(&shell()->env, args[i]);
		else
			replace_envvalue(&shell()->env, str, args[i]);
		free(str);
	}
	return (ret);
}
