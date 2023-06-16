/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_exp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheurtev <lheurtev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:34:47 by qcherel           #+#    #+#             */
/*   Updated: 2022/04/15 14:31:55 by lheurtev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"
#include "../Includes/wildcard_exp.h"

char	**add_wildcard(char **strs, t_dirlist *lst, int *index)
{
	char		**ret;
	t_dirlist	*savenxt;
	int			i;

	i = -1;
	if (lst)
	{
		while (strs[*index][++i])
			lst = sort_direntries(&lst, strs[*index][i]);
		lst = sort_direntries(&lst, 0);
	}
	if (!lst)
	{
		printf("Minishell: no matches found: %s\n", strs[*index]);
		errorspl(strs);
		return (NULL);
	}
	ret = ft_splinsert(strs, dirlst_to_strs(&lst), index);
	while (lst)
	{
		savenxt = lst->next;
		free(lst);
		lst = savenxt;
	}
	return (return_free2(ret, strs[(*index)], strs));
}

char	**wildcard_exp(char **strs)
{
	int	i;

	i = -1;
	while (strs && strs[++i])
	{
		if (find_char(strs[i], '*'))
		{
			if (strs[i][0] == '.')
				strs = add_wildcard(strs, get_direntries(1), &i);
			else
				strs = add_wildcard(strs, get_direntries(0), &i);
			if (!strs)
				return (NULL);
		}
	}
	return (strs);
}

//Search word instead of char