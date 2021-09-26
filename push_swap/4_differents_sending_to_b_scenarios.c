/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_differents_sending_to_b_scenarios.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:27:37 by artmende          #+#    #+#             */
/*   Updated: 2021/09/26 19:51:36 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_to_b_ra_rb(t_stacks_a_b *stacks, t_nbr_list *nbr)
{
	// scenario ra-rb, first let's do index_a - index_b rr
	// then let's do all remaining ra or rb
	// then pb
	while (nbr->index_a && nbr->index_b)
	{
		write(1, "rr\n", 3);
		rr(stacks);
		nbr->index_a--;
		nbr->index_b--;
	}
	while (nbr->index_a)
	{
		write(1, "ra\n", 3);
		ra(stacks);
		nbr->index_a--;
	}
	while (nbr->index_b)
	{
		write(1, "rb\n", 3);
		rb(stacks);
		nbr->index_b--;
	}
	// check that both index are 0 now, but should be the case
	write(1, "pb\n", 3);
	pb(stacks);
}

void	send_to_b_ra_rrb(t_stacks_a_b *stacks, t_nbr_list *nbr)
{
	int	size_stack_b;

	while (nbr->index_a)
	{
		write(1, "ra\n", 3);
		ra(stacks);
		nbr->index_a--;
	}
	size_stack_b = ft_lstsize(stacks->b);
	while (size_stack_b - nbr->index_b)
	{
		write(1, "rrb\n", 4);
		rrb(stacks);
		nbr->index_b++;
	}
	write(1, "pb\n", 3);
	pb(stacks);
}

void	send_to_b_rra_rb(t_stacks_a_b *stacks, t_nbr_list *nbr)
{
	int	size_stack_a;

	size_stack_a = ft_lstsize(stacks->a);
	while (size_stack_a - nbr->index_a)
	{
		write(1, "rra\n", 4);
		rra(stacks);
		nbr->index_a++;
	}
	while (nbr->index_b)
	{
		write(1, "rb\n", 3);
		rb(stacks);
		nbr->index_b--;
	}
	write(1, "pb\n", 3);
	pb(stacks);
}

void	send_to_b_rra_rrb(t_stacks_a_b *stacks, t_nbr_list *nbr)
{
	int	size_stack_a;
	int	size_stack_b;

	size_stack_a = ft_lstsize(stacks->a);
	size_stack_b = ft_lstsize(stacks->b);
	while (size_stack_a - nbr->index_a && size_stack_b - nbr->index_b)
	{
		write(1, "rrr\n", 4);
		rrr(stacks);
		nbr->index_a++;
		nbr->index_b++;
	}
	while (size_stack_a - nbr->index_a)
	{
		write(1, "rra\n", 4);
		rra(stacks);
		nbr->index_a++;
	}
	while (size_stack_b - nbr->index_b)
	{
		write(1, "rrb\n", 4);
		rrb(stacks);
		nbr->index_b++;
	}
	(void)(write(1, "pb\n", 3) && pb(stacks));
}
