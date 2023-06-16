/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathname_exp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <qcherel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:44:25 by qcherel           #+#    #+#             */
/*   Updated: 2022/05/18 18:28:02 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	str_is_cmd(char **strs, int ind)
{
	if (strs[ind][0] == '|' || strs[ind][0] == '>' || strs[ind][0] == '<')
		return (0);
	else if (ind > 0 && (strs[ind - 1][0] == '|'
		|| strs[ind - 1][0] == '>' || strs[ind - 1][0] == '<'))
	{
		return (0);
	}
	return (1);
}

int	is_builtin(char *str, int in, int out)
{
	if (ft_strcmp(str, "cd") == 0)
		return (0);
	if (ft_strcmp(str, "echo") == 0)
		return (0);
	if (ft_strcmp(str, "env") == 0)
		return (0);
	if (ft_strcmp(str, "exit") == 0)
	{
		if (in >= 0 && out >= 0)
		{
			close(in);
			close(out);
		}
		return (0);
	}
	if (ft_strcmp(str, "export") == 0)
		return (0);
	if (ft_strcmp(str, "pwd") == 0)
		return (0);
	if (ft_strcmp(str, "unset") == 0)
		return (0);
	return (1);
}

char	*try_access(char **path, char *str)
{
	char	*ret;
	int		found;
	int		i;

	ret = NULL;
	i = -1;
	if (!str || !is_builtin(str, -1, -1))
		return (str);
	found = -1;
	while (found == -1 && path && path[++i] && notslashed(str))
	{
		if (ret)
			free(ret);
		ret = ft_pathjoin(path[i], str);
		found = access(ret, F_OK);
	}
	if (found == -1)
		found = access(str, F_OK);
	if (!found)
		return (found_pathname(ret, str));
	write(2, "Minishell: Command not found\n", 30);
	shell()->status = 127;
	return (return_free2(str, NULL, ret));
}

char	**pathname_exp(char **strs)
{
	char	**paths;
	int		cmd;
	int		i;

	cmd = 0;
	if (!strs)
		return (NULL);
	paths = ft_split(scan_env("PATH", &shell()->env), ':');
	i = -1;
	while (strs && strs[++i] && !cmd)
	{
		if (str_is_cmd(strs, i))
		{
			strs[i] = try_access(paths, quote_remove(strs[i]));
			if (strs[i] == NULL)
				strs = ft_spldeleteone(strs, i);
			cmd++;
		}
	}
	i = -1;
	while (paths && paths[++i])
		free(paths[i]);
	if (paths)
		free(paths);
	return (wildcard_exp(strs));
}
