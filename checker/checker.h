/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 10:47:26 by artmende          #+#    #+#             */
/*   Updated: 2021/09/17 10:28:49 by artmende         ###   ########.fr       */
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

typedef struct s_malloc_stuff
{
	struct s_stacks_a_b	stacks;
	char				*line;
}				t_malloc_stuff;

void	store_numbers(int argc, char **argv, t_nbr_list **nbr_list);
void	create_nbr_list_from_args(int argc, char **argv, t_nbr_list **nbr_list);
void	create_nbr_list_from_str(char *str, t_nbr_list **nbr_list);

int	sa(t_malloc_stuff *data);
int	sb(t_malloc_stuff *data);
int	ss(t_malloc_stuff *data);
int	pa(t_malloc_stuff *data);
int	pb(t_malloc_stuff *data);
int	ra(t_malloc_stuff *data);
int	rb(t_malloc_stuff *data);
int	rr(t_malloc_stuff *data);
int	rra(t_malloc_stuff *data);
int	rrb(t_malloc_stuff *data);
int	rrr(t_malloc_stuff *data);


void	ft_lstadd_back(t_nbr_list **alst, t_nbr_list *new);
void	free_linked_list(t_nbr_list **alst);
int	call_exit(t_nbr_list **stack_a, t_nbr_list **stack_b, char *line);

int		ft_atoi(const char *str, t_nbr_list **nbr_list);
char	*ft_strchr(const char *s, int c);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strnstr(char *str, char *to_find, size_t len);


#endif
