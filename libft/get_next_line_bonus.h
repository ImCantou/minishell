/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <qcherel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 09:54:12 by qcherel           #+#    #+#             */
/*   Updated: 2022/01/19 17:23:47 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# define MAX_FD 1024

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct s_fdbuf
{
	int		fd;
	char	buf[BUFFER_SIZE + 1];
}	t_fdbuf;

char	*retrieve_buf(t_fdbuf *buflist, int fd);
char	*addbuff_to_line(char *curr, int fd);
char	*get_next_line(int fd);
char	*ft_strnjoin(char *s1, char *s2, int size);
int		ft_strclen(char *str, char c);
void	buf_nextl(char *buf, int n, int size);

#endif
