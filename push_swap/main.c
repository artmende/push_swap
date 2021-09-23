/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:57:26 by artmende          #+#    #+#             */
/*   Updated: 2021/09/23 18:56:46 by artmende         ###   ########.fr       */
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

int	get_nbr_of_element(t_nbr_list *list)
{
	int	nbr_of_element;

	nbr_of_element = 0;
	while (list)
	{
		nbr_of_element++;
		list = list->next;
	}
	return (nbr_of_element);
}

int	find_mid_value(t_nbr_list *list)
{
	int			i;
	int			mid_nbr;
	int			nbr_of_element;
	t_nbr_list	*list_ptr_1;
	t_nbr_list	*list_ptr_2;

	nbr_of_element = get_nbr_of_element(list);
	list_ptr_1 = list;
	while (list_ptr_1)
	{
		i = 0;
		mid_nbr = list_ptr_1->nbr;
		list_ptr_2 = list;
		while (list_ptr_2)
		{
			if (list_ptr_2->nbr > mid_nbr)
				i++;
			list_ptr_2 = list_ptr_2->next;
		}
		if (i == nbr_of_element / 2)
			break ;
		list_ptr_1 = list_ptr_1->next;
	}
	return (mid_nbr);
}

int	list_contains_something_above_mid_value(t_nbr_list *list, int mid_value)
{
	while (list)
	{
		if (list->nbr > mid_value)
			return (1);
		list = list->next;
	}
	return (0);
}

void	send_nbr_to_b(t_stacks_a_b *stacks, int nbr, char u_d)
{
	while (stacks->a && stacks->a->nbr != nbr)
	{ // at the end of this loop, stacks->a points to the number we want to send
		if (u_d == 'u')
		{
			write(1, "ra\n", 4);
			ra(stacks);
		}
		else
		{
			write(1, "rra\n", 5);
			rra(stacks);
		}
	}
	write(1, "pb\n", 4);
	pb(stacks);
}

t_easier_nbr_to_send	find_nbr_to_send_above_mid(t_nbr_list *list, int mid)
{
	int						i;
	t_easier_nbr_to_send	ret;

	i = 0;
	ret.list_size = ft_lstsize(list);
	ret.u_d = 'u';
	while (list)
	{
		if (list->nbr > mid)
		{
			ret.nbr = list->nbr;
			ret.index = i;
			i++;
			list = list->next;
			break ;
		}
		i++;
		list = list->next;
	}
	while (i < ret.list_size / 2 && list)
	{
		i++;
		list = list->next;
	}
	while (list)
	{
		if (list->nbr > mid && ret.list_size - i < ret.index)
		{
			ret.nbr = list->nbr;
			ret.index = ret.list_size - i;
			ret.u_d = 'd';
		}
		i++;
		list = list->next;
	}
	return (ret);
}

void	send_bigger_half_to_b(t_stacks_a_b *stacks)
{
	(void)stacks;
	// regarder le premier et le dernier, si aucun des 2 ne correspond, regarder un rang plus vers le milieu
	// si un des 2 correspond, l'envoyer vers le haut par le chemin le plus court
	// si les 2 correspondent, envoyer celui qui est le plus en haut

	// while (list contain something above mid value)
	// find the closest nbr to send to b
	// apply (ra ou rra) + pb 
	// back to the top of the loop

	int	mid_value;
	t_easier_nbr_to_send	easier_number;

	mid_value = find_mid_value(stacks->a);
	

	while (list_contains_something_above_mid_value(stacks->a, mid_value))
	{
		easier_number = find_nbr_to_send_above_mid(stacks->a, mid_value);
		send_nbr_to_b(stacks, easier_number.nbr, easier_number.u_d);
	}




/* 
	t_nbr_list	*from_top;
	t_nbr_list	*from_bottom;

	from_top = stacks->a;
	from_bottom = stacks->a;
	while (from_bottom && from_bottom->next)
		from_bottom = from_bottom->next;
	while (from_bottom && from_top && from_bottom != from_top)
	{
		if (from_top->nbr > mid_value)
		{
			// send it to the top with ra and pb
			// reinitialize both ptr
			send_nbr_to_b(stacks, from_top->nbr, 'u');
			from_top = stacks->a;
		}
		else if (from_bottom->nbr > mid_value)
		{
			// send it to the top with rra and pb
			// reinitialize both ptr
			send_nbr_to_b(stacks, from_bottom->nbr, 'd');
			from_bottom = stacks->a;
			while (from_bottom && from_bottom->next)
				from_bottom = from_bottom->next;
		}
		else
		{
			from_top = from_top->next;
			if (from_top != from_bottom)
				from_bottom = from_bottom->previous;
		}
	}

 */







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

printf("mid value is : %d\n", find_mid_value(stacks.a));

	t_nbr_list	*ptr1;
	t_nbr_list	*ptr2;






		ptr1 = stacks.a;

	write(1, "\nPrinting stack a from the top :\n", 34);
	while (ptr1)
	{
		printf("%d\n", ptr1->nbr);
		
		if (!ptr1->next)
			ptr2 = ptr1;
		ptr1 = ptr1->next;
	}




	printf("\nSending all above mid value to stack b\n\n");
	send_bigger_half_to_b(&stacks);

		ptr1 = stacks.a;

	write(1, "\nPrinting stack a from the top :\n", 34);
	while (ptr1)
	{
		printf("%d\n", ptr1->nbr);
		
		if (!ptr1->next)
			ptr2 = ptr1;
		ptr1 = ptr1->next;
	}

		ptr1 = stacks.b;

	write(1, "\nPrinting stack b from the top :\n", 34);
	while (ptr1)
	{
		printf("%d\n", ptr1->nbr);
		
		if (!ptr1->next)
			ptr2 = ptr1;
		ptr1 = ptr1->next;
	}


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



