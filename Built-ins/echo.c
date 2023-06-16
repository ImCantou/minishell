/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheurtev <lheurtev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 10:19:20 by qcherel           #+#    #+#             */
/*   Updated: 2022/04/15 15:08:36 by lheurtev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	print_nl(int flag)
{
	if (!flag)
		write(1, "\n", 1);
}

int	_echo(char **args)
{
	int	i;
	int	j;
	int	flag;
	int	text;

	i = 0;
	flag = 0;
	text = 0;
	while (args[++i])
	{
		j = 0;
		while (args[i][j] && args[i][0] == '-' && (!j || args[i][j] == 'n'))
			j++;
		if (text == 0 && args[i][j] == 0 && j > 1)
			flag = 1;
		else
		{
			text = 1;
			write(1, args[i], ft_strlen(args[i]));
			if (args[i + 1])
				write(1, " ", 1);
		}
	}
	print_nl(flag);
	return (0);
}
