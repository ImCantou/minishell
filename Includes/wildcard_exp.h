/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_exp.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheurtev <lheurtev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 11:47:01 by qcherel           #+#    #+#             */
/*   Updated: 2022/05/09 12:19:01 by lheurtev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WILDCARD_EXP_H
# define WILDCARD_EXP_H

# include <dirent.h>
# include <unistd.h>
# include "dirlist.h"

t_dirlist	*get_direntries(int dot);
int			find_char(char *str, char c);
t_dirlist	*unwildsort_dirent(t_dirlist **alst, char c);
t_dirlist	*sort_direntries(t_dirlist **alst, char c);

#endif