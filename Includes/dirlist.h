/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirlist.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheurtev <lheurtev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 11:55:02 by qcherel           #+#    #+#             */
/*   Updated: 2022/05/09 12:19:25 by lheurtev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIRLIST_H
# define DIRLIST_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_dirlist
{
	char	*content;
	void	*next;
	int		last_index;
	int		wild;
}	t_dirlist;

t_dirlist	*ft_dirlstnew(char	*str);
int			ft_dirlstsize(t_dirlist *lst);
void		ft_dirlstaddback(t_dirlist **alst, t_dirlist *add);
char		**dirlst_to_strs(t_dirlist **begin);
t_dirlist	*ft_dirlstremove(t_dirlist **alst, t_dirlist *rm);

#endif