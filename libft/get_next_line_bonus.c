/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 09:53:39 by qcherel           #+#    #+#             */
/*   Updated: 2022/01/05 11:49:52 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*addbuff_to_line(char *curr, int fd)
{
	static t_fdbuf	buflist[MAX_FD];
	char			*buf;
	char			*ret;
	int				size;

	buf = retrieve_buf(buflist, fd);
	if (!buf)
		return (NULL);
	if (!buf[0])
	{
		if (read(fd, buf, BUFFER_SIZE) == -1 || !buf[0])
			return (NULL);
	}
	size = ft_strclen(buf, '\n');
	ret = ft_strnjoin(curr, buf, size);
	if (!ret)
		return (NULL);
	if (curr)
		free(curr);
	buf_nextl(buf, size, BUFFER_SIZE);
	return (ret);
}

char	*get_next_line(int fd)
{
	char	*nline;
	char	*cpy;

	nline = NULL;
	nline = addbuff_to_line(nline, fd);
	while (nline && nline[ft_strlen(nline) - 1] != '\n')
	{
		cpy = nline;
		nline = addbuff_to_line(nline, fd);
		if (!nline)
			return (cpy);
	}
	return (nline);
}
