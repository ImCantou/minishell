/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <qcherel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:15:49 by lheurtev          #+#    #+#             */
/*   Updated: 2022/05/09 12:40:36 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	ft_hslen(char ***s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*createtempfile(void)
{
	char	*file;
	char	*tmp;
	int		i;

	i = -1;
	while (++i != -1)
	{
		tmp = ft_itoa(i);
		file = ft_strjoin(".heredoc", tmp);
		free(tmp);
		if (!access(file, F_OK))
			free(file);
		else
		{
			i = open(file, O_CREAT | O_RDWR, 0644);
			close(i);
			tmp = file;
			file = ft_strjoin("/", tmp);
			free(tmp);
			return (file);
		}
	}
	return (NULL);
}

int	ft_megafree(char **tabfile, int mode)
{
	int	i;

	i = -1;
	if (!tabfile)
		return (0);
	while (tabfile[++i])
	{
		if (mode == 0)
			unlink(tabfile[i]);
		free(tabfile[i]);
	}
	free(tabfile);
	return (0);
}

char	**createtabfile(char ***s, char *tmpfile)
{
	char	**tabfile;
	char	*tmp;
	int		i;
	int		j;

	i = -1;
	j = ft_hslen(s);
	if (checkheredoc(s) == 0)
		return (NULL);
	tabfile = malloc(sizeof(char *) * (j + 1));
	if (!tabfile)
		return (NULL);
	while (++i < j)
	{
		tmp = createtempfile();
		tmpfile = getcwd(NULL, 0);
		tabfile[i] = ft_strjoin(tmpfile, tmp);
		free(tmpfile);
		free(tmp);
	}
	tabfile[i] = NULL;
	return (tabfile);
}

int	ft_heredoccmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (!((s1[i] == 0 && s2[i] == 0) || (s1[i] == 10 && s2[i] == 0)
			|| (s1[i] == 0 && s2[i] == 10)))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
