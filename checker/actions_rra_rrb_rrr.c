/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_rra_rrb_rrr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:26:29 by artmende          #+#    #+#             */
/*   Updated: 2021/09/16 17:11:26 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	rra(t_malloc_stuff *data)
{ // The last element becomes the first one.
	t_nbr_list	*temp1;
	t_nbr_list	*temp2;

	if (!data->stacks.a || !data->stacks.a->next)
		return (0);
	temp1 = data->stacks.a;
	while (temp1->next->next)
		temp1 = temp1->next; // temp1 now has the address of the penultian element that will become the last one
	temp2 = temp1->next; // temp2 has the address of the last element, that we have to move to the top
	temp1->next = 0; // closing the list
	temp2->next = data->stacks.a; // putting the first element after the new first one
	data->stacks.a = temp2; // connecting the pointer of the list to the new first element
	return (0);
}
 
int	rrb(t_malloc_stuff *data)
{ // The last element becomes the first one.
	t_nbr_list	*temp1;
	t_nbr_list	*temp2;

	if (!data->stacks.b || !data->stacks.b->next)
		return (0);
	temp1 = data->stacks.b;
	while (temp1->next->next)
		temp1 = temp1->next; // temp1 now has the address of the penultian element that will become the last one
	temp2 = temp1->next; // temp2 has the address of the last element, that we have to move to the top
	temp1->next = 0; // closing the list
	temp2->next = data->stacks.b; // putting the first element after the new first one
	data->stacks.b = temp2; // connecting the pointer of the list to the new first element
	return (0);
}

int	rrr(t_malloc_stuff *data)
{
	rra(data);
	rrb(data);
	return (0);
}
