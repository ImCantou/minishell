/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_expansion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <qcherel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:10:17 by qcherel           #+#    #+#             */
/*   Updated: 2022/05/13 15:10:57 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

char	**do_expansion(char **strs)
{
	char	**ret;
	char	**tmp;
	char	**tmp2;
	int		i;

	i = -1;
	ret = NULL;
	while (strs[++i])
	{
		strs[i] = param_exp(tilde_exp(strs[i]));
		tmp = field_split(strs[i]);
		if (strs[i])
			free(strs[i]);
		tmp2 = ret;
		ret = ft_spljoin(tmp2, tmp);
		if (tmp2)
			free(tmp2);
		if (tmp)
			free(tmp);
	}
	ret = pathname_exp(ret);
	ret = doquote_removal(ret);
	if (strs)
		free(strs);
	return (ret);
}
