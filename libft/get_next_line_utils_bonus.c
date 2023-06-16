/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheurtev <lheurtev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 09:53:53 by qcherel           #+#    #+#             */
/*   Updated: 2022/03/24 15:23:18 by lheurtev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strclen(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		i++;
	return (i);
}

char	*ft_strnjoin(char *s1, char *s2, int size)
{
	int		i;
	int		j;
	char	*nstr;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	nstr = malloc(sizeof(char) * (ft_strlen(s1) + size + 1));
	if (!nstr)
		return (NULL);
	while (s1 && s1[i])
	{
		nstr[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] && j < size)
	{
		nstr[i + j] = s2[j];
		j++;
	}
	nstr[i + j] = 0;
	return (nstr);
}

void	buf_nextl(char *buf, int n, int size)
{
	int	i;

	i = 0;
	while (i + n < size)
	{
		buf[i] = buf[i + n];
		i++;
	}
	while (i < size)
		buf[i++] = 0;
}

char	*retrieve_buf(t_fdbuf *buflist, int fd)
{
	int	i;

	i = 0;
	while (i < MAX_FD && buflist[i].fd != 0)
	{
		if (buflist[i].fd == fd)
			return (buflist[i].buf);
		i++;
	}
	if (i < MAX_FD)
	{
		buflist[i].fd = fd;
		return (buflist[i].buf);
	}
	return (NULL);
}
