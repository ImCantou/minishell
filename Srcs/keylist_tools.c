/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keylist_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <qcherel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:15:12 by qcherel           #+#    #+#             */
/*   Updated: 2022/05/18 16:47:56 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

char	*create_envkey(char *str)
{
	char	*ret;
	int		i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	ret = malloc(sizeof(char) * (i + 1));
	if (!ret)
		return (NULL);
	i = -1;
	while (str[++i] && str[i] != '=')
		ret[i] = str[i];
	ret[i] = 0;
	return (ret);
}

char	*create_envvalue(char *str)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (i == (int)ft_strlen(str))
		return (NULL);
	ret = malloc(sizeof(char) * (ft_strlen(str) - i));
	if (!ret)
		return (NULL);
	j = 0;
	while (str[++i])
	{
		ret[j] = str[i];
		j++;
	}
	ret[j] = 0;
	return (ret);
}

t_keylist	*new_keylist_elem2(char *key, char *value)
{
	t_keylist	*lst;

	lst = malloc(sizeof(t_keylist));
	if (!lst)
		return (NULL);
	lst->key = create_envkey(key);
	lst->value = value;
	lst->next = NULL;
	return (lst);
}

t_keylist	*new_keylist_elem(char *str)
{
	t_keylist	*lst;

	lst = malloc(sizeof(t_keylist));
	if (!lst)
		return (NULL);
	lst->key = create_envkey(str);
	lst->value = create_envvalue(str);
	lst->next = NULL;
	return (lst);
}

void	free_keylist(t_keylist **lst)
{
	t_keylist	*current;
	t_keylist	*savenxt;

	current = *lst;
	savenxt = NULL;
	while (current)
	{
		if (current->key)
			free(current->key);
		if (current->value)
			free(current->value);
		savenxt = current->next;
		free (current);
		current = savenxt;
	}
	*lst = NULL;
}
