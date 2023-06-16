/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd_cut_tools.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <qcherel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:11:22 by qcherel           #+#    #+#             */
/*   Updated: 2022/05/09 15:08:55 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"

char	**clear_blankstr(char **strs)
{
	int	i;
	int	j;

	i = -1;
	while (strs && strs[++i])
	{
		j = 0;
		while (strs[i][j] == ' ')
			j++;
		if (strs[i][j] == 0)
		{
			free(strs[i]);
			strs = ft_spldeleteone(strs, i);
			i--;
		}
	}
	return (strs);
}

void	errorspl(char **spl)
{
	int	i;

	i = -1;
	while (spl[++i])
		free(spl[i]);
	free(spl);
}

void	parseerrornear(char *token)
{
	write(2, "Minishell: parse error near '", 29);
	write(2, token, ft_strlen(token));
	write(2, "'\n", 2);
}
