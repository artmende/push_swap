/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 10:47:26 by artmende          #+#    #+#             */
/*   Updated: 2021/09/15 17:15:20 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include <stdio.h>

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line/get_next_line.h"



typedef struct s_nbr_list
{
	int						nbr;
	struct s_nbr_list	*next;
}				t_nbr_list;

typedef struct s_stacks_a_b
{
	struct s_nbr_list	*a;
	struct s_nbr_list	*b;
}				t_stacks_a_b;

void	store_numbers(int argc, char **argv, t_nbr_list **nbr_list);
void	create_nbr_list_from_args(int argc, char **argv, t_nbr_list **nbr_list);
void	create_nbr_list_from_str(char *str, t_nbr_list **nbr_list);

void	ft_lstadd_back(t_nbr_list **alst, t_nbr_list *new);
void	free_linked_list(t_nbr_list **alst);
int	call_exit(t_nbr_list **stack_a, t_nbr_list **stack_b, char *line);

int		ft_atoi(const char *str, t_nbr_list **nbr_list);
char	*ft_strchr(const char *s, int c);
void	*ft_memset(void *s, int c, size_t n);


#endif
