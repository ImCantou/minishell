/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheurtev <lheurtev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:17:38 by lheurtev          #+#    #+#             */
/*   Updated: 2022/05/17 12:51:52 by lheurtev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

char	**strdup_redrm(char **s, int a, int b)
{
	char	**dup;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	dup = malloc(sizeof(char *) * (i + 1 - 2));
	if (!dup)
		return (0);
	i = 0;
	free(s[a]);
	free(s[b]);
	while (s[i + (i >= a) + (i + (i >= a) >= b)])
	{
		dup[i] = s[i + (i >= a) + (i + (i >= a) >= b)];
		i++;
	}
	dup[i] = 0;
	free(s);
	return (dup);
}

int	infilefct(char *s2)
{
	int	fd;

	if (!s2)
		return (0);
	if (ft_strcmp(s2, "<") && ft_strcmp(s2, ">"))
	{
		fd = open(s2, O_RDONLY);
		if (fd < 0)
			return (0);
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	else
		return (0);
	return (1);
}

int	outfilefct(char *s2, int mode)
{
	int	fd;

	if (!s2)
		return (0);
	if (ft_strcmp(s2, "<") && ft_strcmp(s2, ">"))
	{
		if (mode == 0)
			fd = open(s2, O_CREAT | O_RDWR | O_TRUNC, 0644);
		else
			fd = open(s2, O_CREAT | O_RDWR | O_APPEND, 0644);
		if (fd < 0)
			return (0);
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	else
		return (0);
	return (1);
}

int	redcmp(char *s1, char *s2)
{
	if (!ft_strcmp(s1, "<"))
		return (infilefct(s2));
	else if (!ft_strcmp(s1, ">"))
		return (outfilefct(s2, 0));
	else if (!ft_strcmp(s1, ">>"))
		return (outfilefct(s2, 1));
	return (2);
}

char	**redfct(char ***s, t_pipeline *pipe, int j, int mode)
{
	int	i;
	int	err;

	i = -1;
	while (s[j][++i])
	{
		err = redcmp(s[j][i], s[j][i + 1]);
		if (!err)
		{
			perror("Redirection error ");
			if (!mode)
				freetest(s, mode);
			if (pipe)
				freepipetab(pipe->pipetab, pipe->len);
			return (NULL);
		}
		else if (err == 1)
		{
			s[j] = strdup_redrm(s[j], i, i + 1);
			i -= 1;
		}
	}
	return (s[j]);
}
