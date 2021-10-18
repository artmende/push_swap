/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:57:26 by artmende          #+#    #+#             */
/*   Updated: 2021/10/18 13:27:06 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	select number of chunks.
	while number of chunks is not 1 -->
		find pivot value based on chunk (we have to send 1/chunk_left elements)
		send all value under pivot to b using fastest way
		chunks-- and back to the top
	<--
	if chunks == 1 -->
		send all to b except for the 3 biggest
		algo with 3 elements (put the biggest down, then swap)
	<--
	push all back to A in order using the fastest way
*/

int	main(int argc, char **argv)
{
	t_stacks_a_b	stacks;

	ft_memset(&stacks, 0, sizeof(stacks));
	store_numbers(argc, argv, &stacks);
	sort_stack_a_chunks(&stacks);
	free_linked_list(&stacks.a);
	free_linked_list(&stacks.b);
	return (0);
}

int	is_list_sorted(t_nbr_list *list)
{
	while (list && list->next)
	{
		if (list->nbr > list->next->nbr)
			return (0);
		list = list->next;
	}
	return (1);
}

int	call_exit(t_nbr_list **list)
{
	free_linked_list(list);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
	return (0);
}
