/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_exp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheurtev <lheurtev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:31:04 by qcherel           #+#    #+#             */
/*   Updated: 2022/05/17 14:50:59 by lheurtev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

char	*replace_questionmark(char *str, int i)
{
	char	*nstr;
	char	*tmp;
	char	*status;
	int		j;

	j = -1;
	nstr = malloc(sizeof(char) * (i + 1));
	status = ft_itoa(shell()->status);
	if (!nstr || !status)
		return (NULL);
	while (++j < i)
		nstr[j] = str[j];
	nstr[j] = 0;
	tmp = ft_strjoin(nstr, status);
	free(status);
	free(nstr);
	nstr = ft_strjoin(tmp, str + i + 2);
	free(tmp);
	return (nstr);
}

void	*return_free2(void *ret, void *p2, void *p1)
{
	if (p1)
		free(p1);
	if (p2)
		free(p2);
	return (ret);
}

char	*replace_name(char *name, char *nstr)
{
	char	*tmp;

	tmp = NULL;
	if (name[0])
		tmp = ft_strjoin(nstr, scan_env(name, &shell()->env));
	else
		tmp = ft_strjoin(nstr, "$");
	return (tmp);
}

char	*replace_arg(char *str, int dol_sign, char *name)
{
	char	*tmp;
	char	*nstr;
	int		i;

	nstr = NULL;
	if (name && !name[0] && str[dol_sign + 1] == '?')
		nstr = replace_questionmark(str, dol_sign);
	else if (name)
	{
		i = -1;
		nstr = malloc(sizeof(char) * (dol_sign + 1));
		if (!nstr)
			return (NULL);
		while (++i < dol_sign)
			nstr[i] = str[i];
		nstr[i] = 0;
		tmp = replace_name(name, nstr);
		free(nstr);
		nstr = ft_strjoin(tmp, str + dol_sign + ft_strlen(name) + 1);
		if (tmp)
			free(tmp);
	}
	return ((char *)return_free2(nstr, str, name));
}

char	*param_exp(char *str)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = ft_strdup(str);
	while (tmp && tmp[++i])
	{
		if (is_unquoted(tmp, i, 1) && tmp[i] == '$')
		{
			if (tmp[i + 1] && tmp[i + 1] == '$')
				i++;
			else if (tmp[i + 1])
			{
				tmp = replace_arg(tmp, i, pars_env(tmp + i));
				if (!tmp)
					return (NULL);
				else if (tmp[i] == 0)
					i--;
			}				
		}
	}
	if (str)
		free(str);
	return (tmp);
}
