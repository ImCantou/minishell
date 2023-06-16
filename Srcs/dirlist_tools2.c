/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirlist_tools2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <qcherel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 11:05:00 by qcherel           #+#    #+#             */
/*   Updated: 2022/04/08 11:58:28 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/dirlist.h"

t_dirlist	*ft_dirlstremove(t_dirlist **alst, t_dirlist *rm)
{
	t_dirlist	*tmp;
	t_dirlist	*lst;

	lst = *alst;
	if (lst == rm)
	{
		*alst = (t_dirlist *)lst->next;
		free(lst->content);
		free(lst);
		return (*alst);
	}
	if (!lst)
		return (NULL);
	while (lst->next && (t_dirlist *)lst->next != rm)
		lst = lst->next;
	tmp = lst->next;
	if (tmp)
	{
		lst->next = tmp->next;
		free(tmp->content);
		free(tmp);
	}
	return (lst->next);
}
