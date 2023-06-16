/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <qcherel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 10:39:43 by qcherel           #+#    #+#             */
/*   Updated: 2022/05/05 12:21:55 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	_pwd(char **args)
{
	char	pwd[PATH_MAX];

	if (!args || !args[0])
		return (127);
	if (getcwd(pwd, sizeof(pwd)) != NULL)
	{
		write(1, pwd, ft_strlen(pwd));
		write(1, "\n", 1);
	}
	return (pwd == NULL);
}
