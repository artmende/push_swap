/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:09:26 by artmende          #+#    #+#             */
/*   Updated: 2021/09/28 18:31:54 by artmende         ###   ########.fr       */
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

int	choose_number_of_chunks(t_stacks_a_b *stacks)
{
	(void)stacks;
	return (13);
}

int	find_pivot_value(int number_of_chunks, t_nbr_list *list)
{
/* 
	find the number that has 1 / nbr_chunks * list_size number lower than him
 */
	int			pivot;
	int			i;
	int			list_size;
	t_nbr_list	*ptr1;
	t_nbr_list	*ptr2;

	ptr1 = list;
	list_size = ft_lstsize(list);
	pivot = 0;
	while (ptr1)
	{
		pivot = ptr1->nbr;
		ptr2 = list;
		i = 0;
		while (ptr2)
		{
			if (ptr2->nbr < pivot)
				i++;
			ptr2 = ptr2->next;
		}
		if (i == list_size / number_of_chunks)
			break ;
		ptr1 = ptr1->next;
	}
	return (pivot);
}

void	send_nbr_to_b_chunks(int size_a, int index_nbr, t_stacks_a_b *stacks)
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


void	choose_nbr_to_send_to_b(int pivot_value, int size_a, t_stacks_a_b *stacks)
{
/* 
	browse all stack a and compare indexes, find the one closer
	rename this function as choose_nbr_to_send
 */
	int	index;
	int	index_nbr_to_send;
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
		index++;
		ptr = ptr->next;
	}
	while (ptr && index < size_a / 2)
		(void)(++index && (ptr = ptr->next));
	while (ptr)
	{
		if (ptr->nbr <= pivot_value && index_nbr_to_send > size_a - index)
			index_nbr_to_send = index;
		index++;
		ptr = ptr->next;
	}
//	printf("index nbr to send is : %d\n", index_nbr_to_send);
	send_nbr_to_b_chunks(size_a, index_nbr_to_send, stacks);
}

int	list_contains_something_less_or_equal_than_pivot(int pivot, t_nbr_list *lst)
{
	while (lst)
	{
		if (lst->nbr <= pivot)
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	send_nbrs_under_pivot_value_to_b(int pivot_value, t_stacks_a_b *stacks)
{
/* 
	while list contain something <= pivot number, call choose nbr
 */

	int	size_a;

	while (list_contains_something_less_or_equal_than_pivot(pivot_value, stacks->a))
	{
		size_a = ft_lstsize(stacks->a);
		choose_nbr_to_send_to_b(pivot_value, size_a, stacks);
	}
}

int	find_fourth_biggest_nbr_in_list(t_nbr_list *list)
{ // get size as a param
	int			i;
	int			list_size;
	int			fourth_biggest;
	t_nbr_list	*ptr1;
	t_nbr_list	*ptr2;

	if (!list)
		return (0);
	list_size = ft_lstsize(list);
	if (list_size < 4)
		return (list->nbr);
	ptr1 = list;
	while (ptr1)
	{
		i = 0;
		fourth_biggest = ptr1->nbr;
		ptr2 = list;
		while (ptr2)
		{
			if (ptr1->nbr > ptr2->nbr)
				i++;
			ptr2 = ptr2->next;
		}
		if (i == list_size - 4)
			break ;
		ptr1 = ptr1->next;
	}
	return (fourth_biggest);
}


void	send_all_to_b_except_3_biggest(t_stacks_a_b *stacks)
{
/* 
	find the 3rd biggest nbr, set it as pivot, and call send_nbr_under_pivot_value_to_b
 */
	int	fourth_biggest_nbr;
	int	size_a;

	size_a = ft_lstsize(stacks->a);
	fourth_biggest_nbr = find_fourth_biggest_nbr_in_list(stacks->a);
	while (list_contains_something_less_or_equal_than_pivot(fourth_biggest_nbr, stacks->a))
	{
		size_a = ft_lstsize(stacks->a);
		choose_nbr_to_send_to_b(fourth_biggest_nbr, size_a, stacks);
	}
}

int	get_index_biggest_nbr(t_nbr_list *list)
{
	int			index;
	int			nbr_max;
	t_nbr_list	*ptr;

	ptr = list;
	if (ptr)
		nbr_max = ptr->nbr;
	while (ptr)
	{
		if (ptr->nbr > nbr_max)
			nbr_max = ptr->nbr;
		ptr = ptr->next;
	}
	ptr = list;
	index = 0;
	while (ptr)
	{
		if (ptr->nbr == nbr_max)
			break ;
		index++;
		ptr = ptr->next;
	}
	return (index);
}

void	sort_a_3_elements(t_stacks_a_b *stacks)
{
	int	index_biggest;

	if (ft_lstsize(stacks->a) < 3)
		return ;
	index_biggest = get_index_biggest_nbr(stacks->a);
	if (index_biggest == 0)
	{
		write(1, "ra\n", 3);
		ra(stacks);
	}
	else
		if (index_biggest == 1)
		{
			write(1, "rra\n", 4);
			rra(stacks);
		}
	if (stacks->a->nbr > stacks->a->next->nbr)
	{
		write(1, "sa\n", 3);
		sa(stacks);
	}
}

void	send_back_to_a_in_order(t_stacks_a_b *stacks)
{
	int	index_biggest_nbr;
	int	size_b;

	while (stacks->b)
	{
		size_b = ft_lstsize(stacks->b);
		index_biggest_nbr = get_index_biggest_nbr(stacks->b);
		if (index_biggest_nbr == 1)
		{
			write(1, "sb\n", 3);
			sb(stacks);
			continue ;
		}
		if (index_biggest_nbr <= size_b / 2)
		{
			while (index_biggest_nbr)
			{
				write(1, "rb\n", 3);
				rb(stacks);
				index_biggest_nbr--;
			}
			write(1, "pa\n", 3);
			pa(stacks);
		}
		else
		{
			while (size_b - index_biggest_nbr)
			{
				write(1, "rrb\n", 4);
				rrb(stacks);
				index_biggest_nbr++;
			}
			write(1, "pa\n", 3);
			pa(stacks);
		}
	}
}


void	sort_stack_a_chunks(t_stacks_a_b *stacks)
{
	int	number_of_chunks;
	int	pivot_value;

	number_of_chunks = choose_number_of_chunks(stacks);
	while (number_of_chunks > 1)
	{
		pivot_value = find_pivot_value(number_of_chunks, stacks->a);
//		printf("pivot is %d\n", pivot_value);
		send_nbrs_under_pivot_value_to_b(pivot_value, stacks);
		number_of_chunks--;
	}
	if (number_of_chunks == 1)
	{
		send_all_to_b_except_3_biggest(stacks);
		sort_a_3_elements(stacks);
	}
	send_back_to_a_in_order(stacks);
}
