/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_ra_rb_rr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:43:56 by artmende          #+#    #+#             */
/*   Updated: 2021/09/16 17:10:52 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ra(t_malloc_stuff *data)
{ // The first element becomes the last one.
	t_nbr_list	*temp1;
	t_nbr_list	*temp2;

	if (!data->stacks.a || !data->stacks.a->next)
		return (0);
	temp1 = data->stacks.a->next; // temp1 has the address of the second element, that will become the first one after the rotation
	temp2 = temp1; // we start at the second element and we go down to the last one. to edit its next pointer and attach the first element
	while (temp2->next)
		temp2 = temp2->next; // temp2 has now the address of the last element
	temp2->next = data->stacks.a; // the first element is attached after the last one
	data->stacks.a->next = 0; // we close the list with 0
	data->stacks.a = temp1;
	return (0);
}

int	rb(t_malloc_stuff *data)
{
	t_nbr_list	*temp1;
	t_nbr_list	*temp2;

	if (!data->stacks.b || !data->stacks.b->next)
		return (0);
	temp1 = data->stacks.b->next;
	temp2 = temp1;
	while (temp2->next)
		temp2 = temp2->next;
	temp2->next = data->stacks.b;
	data->stacks.b->next = 0;
	data->stacks.b = temp1;
	return (0);
}

int	rr(t_malloc_stuff *data)
{
	ra(data);
	rb(data);
	return (0);
}
