/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheurtev <lheurtev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:15:52 by qcherel           #+#    #+#             */
/*   Updated: 2022/05/19 14:56:29 by lheurtev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	perror_executable(char *str)
{
	if (!str || access(str, F_OK))
		return (1);
	if (access(str, X_OK))
	{
		shell()->status = 126;
		perror(str);
		return (1);
	}
	else if (isdir(str))
	{
		shell()->status = 127;
		return (1);
	}
	return (0);
}

int	notslashed(char *s)
{
	int	i;

	if (!s)
		return (1);
	i = -1;
	while (s[++i])
	{
		if (s[i] == '/')
			return (0);
	}
	return (1);
}

void	perror_exit(const char *str)
{
	perror(str);
	exit(errno);
}
