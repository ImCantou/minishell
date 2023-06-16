/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocmain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <qcherel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:59:03 by lheurtev          #+#    #+#             */
/*   Updated: 2022/05/09 12:46:37 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	checkheredoc(char ***s)
{
	int	i;
	int	j;

	i = -1;
	while (s && s[++i])
	{
		j = -1;
		while (s[i][++j])
			if (!ft_strcmp("<<", s[i][j]))
				return (1);
	}
	return (0);
}

int	heredocfct(t_list *lst, t_hdinfo *heredoc, char **str)
{
	char	*ret;

	while (lst)
	{
		ret = readline("myheredoc> \e[0m");
		if (ret)
		{
			if (ret[0])
			{
				if (!ft_strcmp((char *)lst->content, ret))
					str = nextheredoc(str, &lst, heredoc, 0);
				else
					ret = writeinfile(ret, heredoc);
			}
			else
				write(heredoc->fd, "\n", 1);
			if (ret)
				free(ret);
		}
		else if (shell()->status == 130)
			return (1);
		else
			str = nextheredoc(str, &lst, heredoc, 1);
	}
	return (0);
}

int	heredocpars(char **str, t_hdinfo *heredoc)
{
	t_list	*lst;
	int		i;

	i = -1;
	lst = NULL;
	while (str[++i])
		if (!ft_strcmp(str[i], "<<"))
			ft_lstadd_back(&lst, ft_lstnew(ft_strdup(str[i + 1])));
	if (lst)
		i = heredocfct(lst, heredoc, str);
	ft_lstclear(&lst, free);
	if (i == 1)
		return (1);
	else
		return (0);
}

int	parsexec(char ***s, char **tf, int mode)
{
	t_hdinfo	heredoc;

	signal(SIGQUIT, SIG_IGN);
	if (mode == 1)
		signal(SIGINT, SIG_DFL);
	if (!tf)
		return (0);
	heredoc.index = -1;
	heredoc.tabfile = tf;
	while (s && s[++heredoc.index])
	{
		heredoc.fd = open(heredoc.tabfile[heredoc.index],
				O_CREAT | O_RDWR | O_APPEND, 0644);
		heredocpars(s[heredoc.index], &heredoc);
		close (heredoc.fd);
	}
	if (!s)
		return (1);
	return (0);
}
