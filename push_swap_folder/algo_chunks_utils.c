/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_chunks_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:43:46 by artmende          #+#    #+#             */
/*   Updated: 2021/10/05 15:12:15 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	choose_number_of_chunks(t_stacks_a_b *stacks)
{
	if (stacks->nbr_of_element < 2 || is_list_sorted(stacks->a))
		return (-1);
	else if (stacks->nbr_of_element == 2 || stacks->nbr_of_element == 3)
		return (0);
	else if (stacks->nbr_of_element < 20)
		return (1);
	else if (stacks->nbr_of_element < 50)
		return (2);
	else if (stacks->nbr_of_element < 200)
		return (6);
	else
		return (13);
}

/*
	find_pivot_value :
	find the number that has 1 / nbr_chunks * list_size number lower than it
*/

int	find_pivot_value(int number_of_chunks, t_nbr_list *list)
{
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

int	find_fourth_biggest_nbr_in_list(t_nbr_list *list, int list_size, int i)
{
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
			(void)(ptr1->nbr > ptr2->nbr && ++i);
			ptr2 = ptr2->next;
		}
		if (i == list_size - 4)
			break ;
		ptr1 = ptr1->next;
	}
	return (fourth_biggest);
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
