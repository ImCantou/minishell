/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_exp2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <qcherel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 11:42:15 by qcherel           #+#    #+#             */
/*   Updated: 2022/04/08 11:49:46 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"
#include "../Includes/wildcard_exp.h"

t_dirlist	*get_direntries(int dot)
{
	DIR				*curr_dir;
	struct dirent	*entry;
	t_dirlist		*lst;

	curr_dir = opendir(".");
	entry = readdir(curr_dir);
	lst = NULL;
	while (entry)
	{
		if (entry->d_name[0] == '.' && dot)
			ft_dirlstaddback(&lst, ft_dirlstnew(entry->d_name));
		else if (entry->d_name[0] != '.' && !dot)
			ft_dirlstaddback(&lst, ft_dirlstnew(entry->d_name));
		entry = readdir(curr_dir);
	}
	closedir(curr_dir);
	return (lst);
}

int	find_char(char *str, char c)
{
	int	i;

	i = -1;
	while (str && str[++i])
	{
		if (str[i] == c)
			return (1);
	}
	if (str[i] == c)
		return (1);
	return (0);
}

t_dirlist	*unwildsort_dirent(t_dirlist **alst, char c)
{
	t_dirlist	*lst;
	int			index;

	lst = *alst;
	while (lst)
	{
		if ((lst->wild && !find_char(lst->content + lst->last_index + 1, c))
			|| (!lst->wild && lst->content[lst->last_index + 1] != c))
			lst = ft_dirlstremove(alst, lst);
		else
		{
			index = ++lst->last_index;
			if (lst->wild)
			{
				while (lst->content[index] != c)
				{		
					lst->last_index = index++;
				}	
			}
			lst->last_index = index;
			lst->wild = 0;
			lst = lst->next;
		}
	}
	return (*alst);
}

t_dirlist	*sort_direntries(t_dirlist **alst, char c)
{
	t_dirlist	*lst;

	lst = *alst;
	if (c == '*')
	{
		while (lst)
		{
			lst->wild = 1;
			lst = lst->next;
		}
	}
	else
	{
		*alst = unwildsort_dirent(alst, c);
	}
	return (*alst);
}
