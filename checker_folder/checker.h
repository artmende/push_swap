/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 10:47:26 by artmende          #+#    #+#             */
/*   Updated: 2021/09/21 15:52:04 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include "get_next_line/get_next_line.h"

typedef struct s_nbr_list
{
	int					nbr;
	struct s_nbr_list	*next;
}				t_nbr_list;

typedef struct s_stacks_a_b
{
	int					nbr_of_element;
	struct s_nbr_list	*a;
	struct s_nbr_list	*b;
}				t_stacks_a_b;

typedef struct s_malloc_stuff
{
	struct s_stacks_a_b	stacks;
	char				*line;
}				t_malloc_stuff;

/*
**	main.c
*/

void	reading_instructions_loop(t_malloc_stuff *data);
void	verify_stack_a_is_sorted(t_malloc_stuff *data);
int		call_exit(t_nbr_list **stack_a, t_nbr_list **stack_b, char *line);

/*
**	verify_and_store_nbrs.c
*/

void	store_numbers(int argc, char **argv, t_malloc_stuff *data);
void	verify_number_is_not_duplicate(int nbr, t_nbr_list **nbr_list);

/*
**	create_nbr_list_from_str.c
*/

void	create_nbr_list_from_str(char *str, t_malloc_stuff *data);
void	check_number_from_str(char *str);

/*
**	create_nbr_list_from_args.c
*/

void	create_nbr_list_from_args(int argc, char **argv, t_malloc_stuff *data);
void	check_number_from_args(char *str, t_nbr_list **nbr_list);

/*
**	linked_list_add_back_and_free.c
*/

void	ft_lstadd_back(t_nbr_list **alst, t_nbr_list *new);
void	free_linked_list(t_nbr_list **alst);

/*
**	run_actions.c
*/

int		run_action(t_malloc_stuff *data);
int		run_action_len_is_2(t_malloc_stuff *data);
int		run_action_len_is_3(t_malloc_stuff *data);

/*
**	actions_ra_rb_rr.c
*/

int		ra(t_malloc_stuff *data);
int		rb(t_malloc_stuff *data);
int		rr(t_malloc_stuff *data);

/*
**	actions_rra_rrb_rrr.c
*/

int		rra(t_malloc_stuff *data);
int		rrb(t_malloc_stuff *data);
int		rrr(t_malloc_stuff *data);

/*
**	actions_sa_sb_ss_pa_pb.c
*/

int		sa(t_malloc_stuff *data);
int		sb(t_malloc_stuff *data);
int		ss(t_malloc_stuff *data);
int		pa(t_malloc_stuff *data);
int		pb(t_malloc_stuff *data);

/*
**	folder mix_libft
*/

int		ft_atoi(const char *str, t_nbr_list **nbr_list);
char	*ft_strchr(const char *s, int c);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strnstr(char *str, char *to_find, size_t len);

#endif
