/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheurtev <lheurtev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:22:59 by lheurtev          #+#    #+#             */
/*   Updated: 2022/04/15 14:44:55 by lheurtev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

int		specialchecker(char c, char c1);
int		ft_superstrlen(char **str);
int		checktoken(char c);
char	**free_final(char **final);

#endif