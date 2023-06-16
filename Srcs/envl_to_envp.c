/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envl_to_envp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <qcherel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:53:58 by qcherel           #+#    #+#             */
/*   Updated: 2022/05/05 12:24:20 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

char	*strjoin_keyvalue(char *key, char *value)
{
	char	*ret;
	char	*tmp;

	tmp = ft_strjoin(key, "=");
	ret = ft_strjoin(tmp, value);
	free(tmp);
	return (ret);
}

char	**envl_to_envp(t_keylist **begin)
{
	t_keylist	*envl;
	char		**envp;
	int			i;

	i = 0;
	envl = *begin;
	while (envl)
	{
		i++;
		envl = envl->next;
	}
	envp = malloc(sizeof(char *) * (i + 1));
	envl = *begin;
	i = 0;
	while (envl)
	{
		envp[i++] = strjoin_keyvalue(envl->key, envl->value);
		envl = envl->next;
	}
	envp[i] = 0;
	return (envp);
}
