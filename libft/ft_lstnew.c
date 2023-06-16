/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:25:49 by qcherel           #+#    #+#             */
/*   Updated: 2021/11/25 15:49:15 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nlst;

	nlst = malloc(sizeof(t_list));
	if (!nlst)
		return (0);
	nlst->content = content;
	nlst->next = NULL;
	return (nlst);
}
