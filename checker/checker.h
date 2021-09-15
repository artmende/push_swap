/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 10:47:26 by artmende          #+#    #+#             */
/*   Updated: 2021/09/15 13:26:53 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line/get_next_line.h"

int		ft_atoi(const char *str);
char	*ft_strchr(const char *s, int c);

typedef struct s_number_list
{
	int						nbr;
	struct s_number_list	*next;
}				t_number_list;

#endif
