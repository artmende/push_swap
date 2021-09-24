/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:57:58 by artmende          #+#    #+#             */
/*   Updated: 2021/09/24 18:20:40 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

#include <stdio.h>

typedef struct s_nbr_list
{
	int					nbr;
	int					nbr_actions_to_sort;
	int					dir_to_sort;
	struct s_nbr_list	*next;
	struct s_nbr_list	*previous;
}				t_nbr_list;

typedef struct s_stacks_a_b
{
	int					nbr_of_element;
	struct s_nbr_list	*a;
	struct s_nbr_list	*b;
}				t_stacks_a_b;

/* typedef struct s_malloc_stuff
{
	struct s_stacks_a_b	stacks;
	char				*line;
}				t_malloc_stuff; */

typedef struct s_data_to_send_nbr
{
	int			nbr;
	int			index;
	char		u_d;
	int			list_size;
}				t_data_to_send_nbr;

typedef struct s_rot_dir
{
	int	ra_rb; // direction 1
	int	ra_rrb; // direction 2
	int	rra_rb; // direction 3
	int	rra_rrb; // direction 4
}				t_rot_dir;


int	call_exit(t_nbr_list **stack_a, t_nbr_list **stack_b, char *line);

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
char	*ft_strnstr(char *str, char *to_find, size_t len);
int		ft_min(int a, int b);

#endif
