/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_sa_sb_ss_pa_pb.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:01:26 by artmende          #+#    #+#             */
/*   Updated: 2021/09/16 17:28:22 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	sa(t_malloc_stuff *data)
{
	t_nbr_list	*temp1;
	t_nbr_list	*temp2;

	if (!data->stacks.a || !data->stacks.a->next)
		return (0); // if there is no element, or only 1 element, there is nothing to do.
	temp1 = data->stacks.a; // address of first element
	temp2 = data->stacks.a->next->next; // address of third element
	data->stacks.a = data->stacks.a->next; // second element placed at the top
	data->stacks.a->next = temp1; // first element is placed after second
	temp1->next = temp2; // third element is placed after the first one
	return (0);
}

int	sb(t_malloc_stuff *data)
{
	t_nbr_list	*temp1;
	t_nbr_list	*temp2;

	if (!data->stacks.b || !data->stacks.b->next)
		return (0); // if there in only 1 element, there is nothing to do.
	temp1 = data->stacks.b; // address of first element
	temp2 = data->stacks.b->next->next; // address of third element
	data->stacks.b = data->stacks.b->next; // second element placed at the top
	data->stacks.b->next = temp1; // first element is placed after second
	temp1->next = temp2; // third element is placed after the first one
	return (0);
}

int	ss(t_malloc_stuff *data)
{
	sa(data);
	sb(data);
	return (0);
}

int	pa(t_malloc_stuff *data)
{ // from b to a
	t_nbr_list	*temp;

	if (!data->stacks.b)
		return (0); // if b is emtpy, there is nothing to push
	temp = data->stacks.b->next; // second element of stack b that will become the first one
	data->stacks.b->next = data->stacks.a; // all stack a is now under the first element of stack b
	data->stacks.a = data->stacks.b; // the first element of stack b, + all the stack a, is now reattached to the pointer of stack a.
	data->stacks.b = temp; // stack b without its first element is reattached to stack b pointer
	return (0);
}

int	pb(t_malloc_stuff *data)
{ // from a to b
	t_nbr_list	*temp;

	if (!data->stacks.a)
		return (0);
	temp = data->stacks.a->next;
	data->stacks.a->next = data->stacks.b;
	data->stacks.b = data->stacks.a;
	data->stacks.a = temp;
	return (0);
}
