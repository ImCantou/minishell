/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirlist_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheurtev <lheurtev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:59:53 by qcherel           #+#    #+#             */
/*   Updated: 2022/04/15 14:30:00 by lheurtev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/dirlist.h"
#include "../libft/libft.h"

int	ft_dirlstsize(t_dirlist *lst)
{
	int			i;
	t_dirlist	*current;

	i = 0;
	current = lst;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}

t_dirlist	*ft_dirlstnew(char	*str)
{
	t_dirlist	*lst;

	lst = malloc(sizeof(t_dirlist));
	if (!lst)
		return (NULL);
	lst->content = ft_strdup(str);
	if (!lst->content)
	{
		free(lst);
		return (NULL);
	}
	lst->wild = 0;
	lst->last_index = -1;
	lst->next = NULL;
	return (lst);
}

t_dirlist	*ft_dirlstlast(t_dirlist *lst)
{
	t_dirlist	*last;

	last = lst;
	if (!lst)
		return (NULL);
	while (last->next)
		last = last->next;
	return (last);
}

void	ft_dirlstaddback(t_dirlist **alst, t_dirlist *add)
{
	t_dirlist	*last;

	if (*alst)
	{
		last = ft_dirlstlast(*alst);
		if (last)
			last->next = add;
	}
	else
		*alst = add;
}

char	**dirlst_to_strs(t_dirlist **begin)
{
	t_dirlist	*lst;
	char		**strs;
	int			i;

	i = -1;
	lst = *begin;
	strs = malloc(sizeof(char *) * (ft_dirlstsize(lst) + 1));
	if (!strs)
		return (NULL);
	lst = *begin;
	while (lst)
	{
		strs[++i] = lst->content;
		lst = lst->next;
	}
	strs[++i] = 0;
	return (strs);
}
