/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathname_exp_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheurtev <lheurtev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:57:14 by lheurtev          #+#    #+#             */
/*   Updated: 2022/05/19 14:16:24 by lheurtev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

char	*is_exec(char *path)
{
	if (!path)
		return (NULL);
	if (!access(path, X_OK))
		return (path);
	else
	{
		free(path);
		return (NULL);
	}
}

int	isdir(char *path)
{
	struct stat	statbuf;

	if (stat(path, &statbuf) != 0)
		return (0);
	if (S_ISDIR(statbuf.st_mode))
	{
		write(2, path, ft_strlen(path));
		write(2, " : Is a directory\n", 18);
		return (1);
	}
	return (0);
}

char	*found_pathname(char *ret, char *str)
{
	char	*qrm;
	char	*dup;

	dup = ft_strdup(str);
	qrm = quote_remove(dup);
	if (!qrm || qrm[0] == 0)
	{
		write(2, "Minishell: Command not found\n", 29);
		free(str);
		if (ret)
			free(ret);
		if (qrm)
			free(qrm);
		return (NULL);
	}
	free (qrm);
	if (!ret || access(ret, F_OK))
	{
		if (ret)
			free(ret);
		return (str);
	}
	free(str);
	return (ret);
}
