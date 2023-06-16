/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <qcherel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:55:10 by lheurtev          #+#    #+#             */
/*   Updated: 2022/05/19 11:35:02 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// -----------------Includes----------------------

# include <stdio.h>
# include <linux/limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../Includes/perror_exit.h"
# include "../Includes/_shell.h"
# include "../Includes/exec.h"
# include "../Includes/parsing.h"

// -------------------Defines---------------------

# define ALL_TOKENS 0
# define PIPE_TOKEN 1
# define REDIR_TOKEN 2

// -------------Typedefs & Structs----------------

typedef struct s_inout
{
	int	infile;
	int	outfile;
}	t_inout;

typedef struct s_cmd
{
	t_inout	file;
	char	*path;
	char	**args;
}	t_cmd;

// ------------------Fonctions--------------------

//	Built-ins
int			_env(char **env);
int			_cd(char **args);
int			_echo(char **args);
int			bi_exit(char **args);
int			exitfonction(char ***s, int i, t_pipeline *pipe);
int			_export(char **args);
int			_pwd(char **args);
int			_unset(char **args);
int			ft_exit(char *n);

// Expansions fonctions
char		**do_expansion(char **strs);
char		*tilde_exp(char *str);
char		*param_exp(char *str);
char		**field_split(char *s);
char		**pathname_exp(char **strs);
char		**wildcard_exp(char **strs);
char		*quote_remove(char *str);
char		**doquote_removal(char **strs);

//	Main Fonctions
int			minishell(char *str);
char		**firstlexer(char *str);
char		***simple_cmd_cut(char **token_recognition);
int			parsexec(char ***s, char **tf, int mode);
void		handler(int signum);

//	Global Access to Env
t_shell		*shell(void);

//	Env	tools
t_keylist	*create_envlist(char **envp);
char		*scan_env(char *key, t_keylist **begin);
char		*pars_env(char *str);

//	Keylist tools
char		*create_envkey(char *str);
char		*create_envvalue(char *str);
void		add_to_env(t_keylist **begin, char *str);
void		add_to_env2(t_keylist **begin, char *key, char *value);
t_keylist	*new_keylist_elem(char *str);
t_keylist	*new_keylist_elem2(char *key, char *value);
void		free_keylist(t_keylist **lst);

//	Tools
int			notslashed(char *s);
int			perror_executable(char *str);
int			isdir(char *path);
void		print_fading_minishell(void);
void		errorspl(char **spl);
char		*is_exec(char *path);
char		*found_pathname(char *ret, char *str);
char		**clear_blankstr(char **strs);
int			is_unquoted(char *str, int i, int f);
void		*return_free2(void *ret, void *p2, void *p1);
char		**envl_to_envp(t_keylist **begin);
int			is_builtin(char *str, int in, int out);
int			ft_hslen(char ***s);
int			ft_megafree(char **heredoc, int mode);
void		parseerrornear(char *token);

#endif
