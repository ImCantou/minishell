/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:25:23 by qcherel           #+#    #+#             */
/*   Updated: 2021/11/30 15:23:20 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin;
	t_list	*nextchain;

	if (!lst)
		return (NULL);
	begin = 0;
	while (lst)
	{
		nextchain = ft_lstnew((*f)(lst->content));
		if (!nextchain)
		{
			ft_lstclear(&begin, del);
			return (NULL);
		}
		ft_lstadd_back(&begin, nextchain);
		lst = lst->next;
	}
	return (begin);
}
