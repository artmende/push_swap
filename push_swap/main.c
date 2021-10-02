/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:57:26 by artmende          #+#    #+#             */
/*   Updated: 2021/10/02 11:33:42 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	1) Store numbers in stack A
**	2) Select an algorithm
**	3) Execute algorithm and write each action
**	4) verify its sorted ?
**
*/




/* 

	1) send the first 2 elements to B.
	2) check if the biggest of the 2 is at the top, if not swap b
	3) browse stack A and for all numbers save the moving type and number of action
	4) select the number with fewest actions and call the right scenario with number to move
	5) the scenario function execute the moves
	6) back to point 3, until stack A is empty
	7) pa until stack B is empty



 */

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

int	call_exit(t_nbr_list **list)
{
	free_linked_list(list);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
	return (0);
}



