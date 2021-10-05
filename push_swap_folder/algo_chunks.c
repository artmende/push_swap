/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:09:26 by artmende          #+#    #+#             */
/*   Updated: 2021/10/05 15:40:16 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	select number of chunks.
	while number of chunks is not 1 -->
		find pivot value based on chunk (we have to send 1/chunk_left elements)
		send all value under or equal to pivot to b using fastest way
		chunks-- and back to the top
	<--
	if chunks == 1 -->
		send all to b except for the 3 biggest
		algo with 3 elements (put the biggest down, then swap)
	<--
	push all back to A in order using the fastest way
*/

void	sort_stack_a_chunks(t_stacks_a_b *stacks)
{
	int	number_of_chunks;
	int	pivot_value;

	number_of_chunks = choose_number_of_chunks(stacks);
	if (number_of_chunks == -1)
		return ;
	while (number_of_chunks > 1)
	{
		pivot_value = find_pivot_value(number_of_chunks, stacks->a);
		send_nbrs_under_pivot_value_to_b(pivot_value, stacks);
		number_of_chunks--;
	}
	if (number_of_chunks == 1)
	{
		send_all_to_b_except_3_biggest(stacks);
		sort_a_2_or_3_elements(stacks);
	}
	if (!number_of_chunks)
		sort_a_2_or_3_elements(stacks);
	send_back_to_a_in_order(stacks);
}

void	sort_a_2_or_3_elements(t_stacks_a_b *stacks)
{
	int	index_biggest;
	int	size_a;

	size_a = ft_lstsize(stacks->a);
	if (size_a < 2)
		return ;
	index_biggest = get_index_biggest_nbr(stacks->a);
	if (index_biggest == 0)
	{
		write(1, "ra\n", 3);
		ra(stacks);
	}
	else
	{
		if (index_biggest == 1 && size_a == 3)
		{
			write(1, "rra\n", 4);
			rra(stacks);
		}
	}
	if (stacks->a->nbr > stacks->a->next->nbr)
	{
		write(1, "sa\n", 3);
		sa(stacks);
	}
}

/*
	send_back_to_a_in_order :
	index_biggest_nbr is determined again after every single rb or rrb
	That is not so effective, but it was an easy way to make sure sb is used
	as much as possible, to save some rrb
*/

void	send_back_to_a_in_order(t_stacks_a_b *stacks)
{
	int	index_biggest_nbr;
	int	size_b;

	while (stacks->b)
	{
		size_b = ft_lstsize(stacks->b);
		index_biggest_nbr = get_index_biggest_nbr(stacks->b);
		if (!index_biggest_nbr)
		{
			write(1, "pa\n", 3);
			pa(stacks);
			continue ;
		}
		if (index_biggest_nbr == 1)
		{
			write(1, "sb\n", 3);
			sb(stacks);
			continue ;
		}
		if (index_biggest_nbr <= size_b / 2)
			(void)(write(1, "rb\n", 3) && rb(stacks));
		else
			(void)(write(1, "rrb\n", 4) && rrb(stacks));
	}
}
