/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:11:50 by qcherel           #+#    #+#             */
/*   Updated: 2021/11/26 17:11:58 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*savenxt;

	current = *lst;
	savenxt = NULL;
	while (current)
	{
		(*del)(current->content);
		savenxt = current->next;
		free (current);
		current = savenxt;
	}
	*lst = NULL;
}
