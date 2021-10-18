/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_nbr_to_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:36:10 by artmende          #+#    #+#             */
/*   Updated: 2021/10/18 11:09:23 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_nbrs_under_pivot_value_to_b(int pivot_value, t_stacks_a_b *stacks)
{
	int	size_a;

	while (list_contains_something_less_or_equal_than_pivot(pivot_value,
			stacks->a))
	{
		size_a = ft_lstsize(stacks->a);
		choose_nbr_to_send(pivot_value, size_a, stacks);
	}
}

/*
	choose_nbr_to_send :
	browse all stack a and compare indexes, find the one closer
*/

void	choose_nbr_to_send(int pivot_value, int size_a, t_stacks_a_b *stacks)
{
	int			index;
	int			index_nbr_to_send;
	t_nbr_list	*ptr;

	index = 0;
	ptr = stacks->a;
	while (ptr && index < size_a)
	{
		if (ptr->nbr <= pivot_value)
		{
			index_nbr_to_send = index;
			break ;
		}
		(void)(++index && (ptr = ptr->next));
	}
	while (ptr && index < size_a / 2)
		(void)(++index && (ptr = ptr->next));
	while (ptr)
	{
		if (ptr->nbr <= pivot_value && index_nbr_to_send > size_a - index)
			index_nbr_to_send = index;
		(void)(++index && (ptr = ptr->next));
	}
	send_nbr_to_b(size_a, index_nbr_to_send, stacks);
}

void	send_nbr_to_b(int size_a, int index_nbr, t_stacks_a_b *stacks)
{
	if (index_nbr <= size_a / 2)
	{
		while (index_nbr)
		{
			write(1, "ra\n", 3);
			ra(stacks);
			index_nbr--;
		}
	}
	else
	{
		while (size_a - index_nbr)
		{
			write(1, "rra\n", 4);
			rra(stacks);
			index_nbr++;
		}
	}
	write(1, "pb\n", 3);
	pb(stacks);
}

void	send_all_to_b_except_3_biggest(t_stacks_a_b *stacks)
{
	int	fourth_biggest_nbr;
	int	size_a;

	size_a = ft_lstsize(stacks->a);
	fourth_biggest_nbr = find_fourth_biggest_nbr_in_list(stacks->a, size_a, 0);
	while (list_contains_something_less_or_equal_than_pivot(fourth_biggest_nbr,
			stacks->a))
	{
		size_a = ft_lstsize(stacks->a);
		choose_nbr_to_send(fourth_biggest_nbr, size_a, stacks);
	}
}
