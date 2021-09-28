/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:09:26 by artmende          #+#    #+#             */
/*   Updated: 2021/09/28 11:53:04 by artmende         ###   ########.fr       */
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
	return (3);
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

void	send_nbr_under_pivot_value_to_b(int pivot_value, t_stacks_a_b *stacks)
{

}


void	sort_stack_a_chunks(t_stacks_a_b *stacks)
{
	int	number_of_chunks;
	int	pivot_value;

	number_of_chunks = choose_number_of_chunks(stacks);
	while (number_of_chunks > 1)
	{
		pivot_value = find_pivot_value(number_of_chunks, stacks->a);
		send_nbr_under_pivot_value_to_b(pivot_value, stacks);
		number_of_chunks--;
	}
	if (number_of_chunks == 1)
	{
//		send_all_to_b_except_3_biggest(stacks);
//		sort_a_3_elements(stacks);
	}
//	send_back_to_a_in_order(stacks);
}
