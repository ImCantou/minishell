/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheurtev <lheurtev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:06:05 by qcherel           #+#    #+#             */
/*   Updated: 2022/05/17 14:44:32 by lheurtev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

char	*pars_env(char *str)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	while ((str[++i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)
		|| (str[i] >= 48 && str[i] <= 57 && i != 1) || str[i] == 95)
		j++;
	ret = malloc(sizeof(char) * i);
	i = -1;
	while (++i < j)
		ret[i] = str[i + 1];
	ret[i] = 0;
	return (ret);
}

char	*scan_env(char *key, t_keylist **begin)
{
	t_keylist	*lst;

	lst = *begin;
	while (lst)
	{
		if (ft_strcmp(key, lst->key) == 0)
			return (lst->value);
		lst = lst->next;
	}
	return (NULL);
}

void	add_to_env2(t_keylist **begin, char *key, char *value)
{
	t_keylist	*last;

	if (*begin)
	{
		last = *begin;
		while (last->next)
		{
			last = last->next;
		}
		if (last)
			last->next = new_keylist_elem2(key, value);
	}
	else
		*begin = new_keylist_elem2(key, value);
}

void	add_to_env(t_keylist **begin, char *str)
{
	t_keylist	*last;

	if (*begin)
	{
		last = *begin;
		while (last->next)
		{
			last = last->next;
		}
		if (last)
			last->next = new_keylist_elem(str);
	}
	else
		*begin = new_keylist_elem(str);
}

t_keylist	*create_envlist(char **envp)
{
	t_keylist	*env_lst;
	int			i;

	env_lst = NULL;
	i = -1;
	while (envp[++i])
		add_to_env(&env_lst, envp[i]);
	return (env_lst);
}
