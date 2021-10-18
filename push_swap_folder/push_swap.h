/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:57:58 by artmende          #+#    #+#             */
/*   Updated: 2021/10/18 11:08:44 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

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

/*
**	main.c
*/

int		is_list_sorted(t_nbr_list *list);
int		call_exit(t_nbr_list **list);

/*
**	verify_and_store_nbrs.c
*/

void	store_numbers(int argc, char **argv, t_stacks_a_b *stacks);
void	verify_number_is_not_duplicate(int nbr, t_nbr_list **nbr_list);

/*
**	create_nbr_list_from_str.c
*/

void	create_nbr_list_from_str(char *str, t_stacks_a_b *stacks);
void	check_number_from_str(char *str);

/*
**	create_nbr_list_from_args.c
*/

void	create_nbr_list_from_args(int argc, char **argv, t_stacks_a_b *stacks);
void	check_number_from_args(char *str, t_nbr_list **nbr_list);

/*
**	linked_list_add_back_and_free.c
*/

void	ft_lstadd_back(t_nbr_list **alst, t_nbr_list *new);
void	free_linked_list(t_nbr_list **alst);
int		ft_lstsize(t_nbr_list *lst);

/*
**	algo_chunks.c
*/

void	send_back_to_a_in_order(t_stacks_a_b *stacks);
void	sort_stack_a_chunks(t_stacks_a_b *stacks);
void	sort_a_2_or_3_elements(t_stacks_a_b *stacks);

/*
**	algo_chunks_utils.c
*/

int		choose_number_of_chunks(t_stacks_a_b *stacks);
int		find_pivot_value(int number_of_chunks, t_nbr_list *list);
int		list_contains_something_less_or_equal_than_pivot(int pivot,
			t_nbr_list *lst);
int		find_fourth_biggest_nbr_in_list(t_nbr_list *list, int list_size, int i);
int		get_index_biggest_nbr(t_nbr_list *list);

/*
**	send_nbr_to_b.c
*/

void	send_nbrs_under_pivot_value_to_b(int pivot_value, t_stacks_a_b *stacks);
void	choose_nbr_to_send(int pivot_value, int size_a, t_stacks_a_b *stacks);
void	send_nbr_to_b(int size_a, int index_nbr, t_stacks_a_b *stacks);
void	send_all_to_b_except_3_biggest(t_stacks_a_b *stacks);

/*
**	actions_ra_rb_rr.c
*/

int		ra(t_stacks_a_b *stacks);
int		rb(t_stacks_a_b *stacks);
int		rr(t_stacks_a_b *stacks);

/*
**	actions_rra_rrb_rrr.c
*/

int		rra(t_stacks_a_b *stacks);
int		rrb(t_stacks_a_b *stacks);
int		rrr(t_stacks_a_b *stacks);

/*
**	actions_sa_sb_ss_pa_pb.c
*/

int		sa(t_stacks_a_b *stacks);
int		sb(t_stacks_a_b *stacks);
int		ss(t_stacks_a_b *stacks);
int		pa(t_stacks_a_b *stacks);
int		pb(t_stacks_a_b *stacks);

/*
**	folder mix_libft
*/

int		ft_atoi(const char *str, t_nbr_list **nbr_list);
char	*ft_strchr(const char *s, int c);
void	*ft_memset(void *s, int c, size_t n);

#endif
