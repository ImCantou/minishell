/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoctools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <qcherel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:56:13 by lheurtev          #+#    #+#             */
/*   Updated: 2022/05/09 12:47:41 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

char	*heredocread(char *start, char *end, int fd)
{
	char	*ret;
	char	*final;

	ret = get_next_line(fd);
	while (ft_heredoccmp(ret, start))
	{
		if (ret)
			free(ret);
		ret = get_next_line(fd);
	}
	while (ft_heredoccmp(ret, end))
	{
		if (ret)
			free(ret);
		ret = get_next_line(fd);
		if (ft_heredoccmp(ret, end))
			final = ft_strjoin(final, ret);
	}
	return (final);
}

char	**changehstr(t_hdinfo *heredoc, char **str)
{
	int		i;

	i = 0;
	while (ft_strcmp(str[i], "<<"))
		i++;
	free(str[i]);
	free(str[i + 1]);
	str[i] = ft_strdup("<");
	str[i + 1] = ft_strdup(heredoc->tabfile[heredoc->index]);
	return (str);
}

t_list	*nextstopword(t_list *lst, t_hdinfo *heredoc)
{
	if (lst->next)
	{
		close(heredoc->fd);
		heredoc->fd = open(heredoc->tabfile[heredoc->index],
				O_RDWR | O_TRUNC, 0644);
	}
	return (lst->next);
}

char	**nextheredoc(char **str, t_list **lst, t_hdinfo *heredoc, int mode)
{
	if (mode == 1)
		printf("error: heredoc delimited by EOF (wanted `%s')\n",
			(char *)(*lst)->content);
	str = changehstr(heredoc, str);
	*lst = nextstopword(*lst, heredoc);
	return (str);
}

char	*writeinfile(char *ret, t_hdinfo *heredoc)
{
	ret = param_exp(ret);
	if (ret)
		write(heredoc->fd, ret, ft_strlen(ret));
	write(heredoc->fd, "\n", 1);
	return (ret);
}
