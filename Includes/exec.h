/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheurtev <lheurtev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:18:09 by lheurtev          #+#    #+#             */
/*   Updated: 2022/05/17 15:35:58 by lheurtev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <sys/wait.h>

typedef struct s_hdinfo
{
	int		index;
	int		fd;
	char	**tabfile;
}	t_hdinfo;

typedef struct s_pipeline
{
	int	len;
	int	savedstdin;
	int	savedstdout;
	int	**pipetab;
}	t_pipeline;

int		ft_heredoccmp(const char *s1, const char *s2);
int		exec(char ***s);
int		ft_hslen(char ***s);
int		checkheredoc(char ***s);
int		**createpipetab(int len);
int		pipex(char ***s, t_pipeline *execpipe, int i);
int		execbuiltin(char *str, char ***s, int i, t_pipeline *pipe);
int		dupnclose(int in, int out, int ret);

char	**redfct(char ***s, t_pipeline *pipe, int j, int mode);
char	**createtabfile(char ***s, char *tmpfile);
char	**nextheredoc(char **str, t_list **lst, t_hdinfo *heredoc, int mode);
char	*writeinfile(char *ret, t_hdinfo *heredoc);

void	exechandler(int signum);
void	closetab(int **tab, int len);
void	freepipetab(int **tab, int len);
void	sigfct(int pid);
void	freetest(char ***lol, int mode);
void	catchsignal(int status);

#endif