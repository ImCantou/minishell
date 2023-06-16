/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _shell.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheurtev <lheurtev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:42:59 by qcherel           #+#    #+#             */
/*   Updated: 2022/05/09 12:18:37 by lheurtev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SHELL_H
# define _SHELL_H

typedef struct s_keylist
{
	char	*key;
	char	*value;
	void	*next;
}	t_keylist;

struct s_mainargs
{
	int		ac;
	char	**av;
	char	**envp;
};

typedef struct s_shell
{
	t_keylist			*env;
	struct s_mainargs	*margs;
	int					status;
}	t_shell;

t_shell	*_shell(void);

#endif