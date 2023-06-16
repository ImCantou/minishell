/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror_exit.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcherel <qcherel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 10:53:10 by qcherel           #+#    #+#             */
/*   Updated: 2022/03/03 13:30:23 by qcherel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERROR_EXIT_H
# define PERROR_EXIT_H

# include <stdio.h>
# include <errno.h>
# include <stdlib.h>

void	perror_exit(const char *str);

#endif