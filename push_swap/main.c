/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:57:26 by artmende          #+#    #+#             */
/*   Updated: 2021/09/24 15:54:08 by artmende         ###   ########.fr       */
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
			write(1, "ra\n", 3);
			ra(stacks);
		}
		else
		{
			write(1, "rra\n", 4);
			rra(stacks);
		}
	}
	write(1, "pb\n", 3);
	pb(stacks);
}

void	send_nbr_to_a(t_stacks_a_b *stacks, int nbr, char u_d)
{
	while (stacks->b && stacks->b->nbr != nbr)
	{ // at the end of this loop, stacks->b points to the number we want to send
		if (u_d == 'u')
		{
			write(1, "rb\n", 3);
			rb(stacks);
		}
		else
		{
			write(1, "rrb\n", 4);
			rrb(stacks);
		}
	}
	write(1, "pa\n", 3);
	pa(stacks);
}





t_data_to_send_nbr	find_nbr_to_send_above_mid(t_nbr_list *list, int mid)
{
	int						i;
	t_data_to_send_nbr	ret;

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
	t_data_to_send_nbr	easier_number;

	mid_value = find_mid_value(stacks->a);
	

	while (list_contains_something_above_mid_value(stacks->a, mid_value))
	{
		easier_number = find_nbr_to_send_above_mid(stacks->a, mid_value);
		send_nbr_to_b(stacks, easier_number.nbr, easier_number.u_d);
	}
}

t_data_to_send_nbr	find_biggest_nbr_and_direction(t_nbr_list *list)
{
	int					i;
	t_data_to_send_nbr	ret;
	
	i = 0;
	ret.list_size = ft_lstsize(list);
	ret.u_d = 'u';
	if (list)
		ret.nbr = list->nbr;
	while (list)
	{
		if (list->nbr > ret.nbr)
		{
			ret.nbr = list->nbr;
			if (i > ret.list_size / 2)
				ret.u_d = 'd';
		}
		i++;
		list = list->next;
	}
	return (ret);
}

int	get_biggest_nbr_in_list(t_nbr_list *list)
{
	int	biggest_number;

	biggest_number = 0;
	if (list)
		biggest_number = list->nbr;

/* 	while (list)
	{
		if (biggest_number < list->nbr)
			biggest_number = list->nbr;
		list = list->next;
	} */

	while (list->next)
	{
		if (biggest_number < list->next->nbr)
			biggest_number = list->next->nbr;
		list = list->next;
	}


	return (biggest_number);
}

void	send_numbers_back_to_a(t_stacks_a_b *stacks)
{
	t_data_to_send_nbr	nbr_to_send;

	while (stacks->b)
	{
		nbr_to_send = find_biggest_nbr_and_direction(stacks->b);
		send_nbr_to_a(stacks, nbr_to_send.nbr, nbr_to_send.u_d);
	}
}

void	send_small_numbers_to_b(t_stacks_a_b *stacks)
{
	int	nbr_max;
	t_nbr_list	*ptr;

//	nbr_max = get_biggest_nbr_in_list(stacks->a);
	ptr = stacks->a;
	if (ptr)
		nbr_max = ptr->nbr;
	while (ptr && ptr->next)
	{
		if (ptr->next->nbr > nbr_max)
			nbr_max = ptr->next->nbr;
		ptr = ptr->next;
	} // ptr is now on the last element of stack a
	while (ptr && ptr->nbr != nbr_max)
	{
		rra(stacks);
		pb(stacks);
		write(1, "rra\npb\n", 7);
		ptr = stacks->a;
		while (ptr && ptr->next)
			ptr = ptr->next;
	}
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

//	printf("mid value is : %d\n", find_mid_value(stacks.a));
//	printf("MAX nbr is %d\n", get_biggest_nbr_in_list(stacks.a));

	t_nbr_list	*ptr1;
	t_nbr_list	*ptr2;






		ptr1 = stacks.a;

//	write(1, "\nPrinting stack a from the top :\n", 34);
	while (ptr1)
	{
//		printf("%d\n", ptr1->nbr);
		
		if (!ptr1->next)
			ptr2 = ptr1;
		ptr1 = ptr1->next;
	}

//	t_data_to_send_nbr biggest_number = find_biggest_nbr_and_direction(stacks.a);

//	printf("biggest number is %d and it has to be sent with direction %c\n", biggest_number.nbr, biggest_number.u_d);


/* 
	printf("\nSending all above mid value to stack b\n\n");
	printf("Sending back to A in order\n\n");
	printf("Sending all small numbers to stack b\n\n");
	printf("Sending back to A in order\n\n"); */
	
	send_bigger_half_to_b(&stacks);
	send_numbers_back_to_a(&stacks);
	send_small_numbers_to_b(&stacks);
	send_numbers_back_to_a(&stacks);




		ptr1 = stacks.a;

//	write(1, "\nPrinting stack a from the top :\n", 33);
	while (ptr1)
	{
//		printf("%d\n", ptr1->nbr);
		
		if (!ptr1->next)
			ptr2 = ptr1;
		ptr1 = ptr1->next;
	}

		ptr1 = stacks.b;

//	write(1, "\nPrinting stack b from the top :\n", 33);
	while (ptr1)
	{
//		printf("%d\n", ptr1->nbr);
		
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



