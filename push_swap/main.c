/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:57:26 by artmende          #+#    #+#             */
/*   Updated: 2021/09/22 17:48:42 by artmende         ###   ########.fr       */
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

int	find_mid_value(t_stacks_a_b *stacks)
{
	int			i;
	int			mid_nbr;
	t_nbr_list	*list_ptr_1;
	t_nbr_list	*list_ptr_2;

	list_ptr_1 = stacks->a;
	while (list_ptr_1)
	{
		i = 0;
		mid_nbr = list_ptr_1->nbr;
		list_ptr_2 = stacks->a;
		while (list_ptr_2)
		{
			if (list_ptr_2->nbr > mid_nbr)
				i++;
			list_ptr_2 = list_ptr_2->next;
		}
		if (i == stacks->nbr_of_element / 2)
			break ;
		list_ptr_1 = list_ptr_1->next;
	}
	return (mid_nbr);
}

void	send_bigger_half_to_b(t_stacks_a_b *stacks)
{
	(void)stacks;
}

int	main(int argc, char **argv)
{
	t_stacks_a_b	stacks;

	ft_memset(&stacks, 0, sizeof(stacks));
	store_numbers(argc, argv, &stacks);

	// send bigger half to B
	// send back b to a in order
	// reverse and send to b smaller half
	// send back b to a in order

	return (0);
}

int	call_exit(t_nbr_list **stack_a, t_nbr_list **stack_b, char *line)
{
	(void)line;
	free_linked_list(stack_a);
	free_linked_list(stack_b);
//	free(line);
	write(2, "Error\n", 7);
	exit(EXIT_FAILURE);
	return (0);
}



