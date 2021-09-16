/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_sa_sb_ss_pa_pb.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:01:26 by artmende          #+#    #+#             */
/*   Updated: 2021/09/16 11:37:59 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_malloc_stuff *data)
{
	t_nbr_list	*temp1;
	t_nbr_list	*temp2;

	if (!data->stacks.a || !data->stacks.a->next)
		return ; // if there is no element, or only 1 element, there is nothing to do.
	temp1 = data->stacks.a; // address of first element
	temp2 = data->stacks.a->next->next; // address of third element
	data->stacks.a = data->stacks.a->next; // second element placed at the top
	data->stacks.a->next = temp1; // first element is placed after second
	temp1->next = temp2; // third element is placed after the first one
}

void	sb(t_malloc_stuff *data)
{
	t_nbr_list	*temp1;
	t_nbr_list	*temp2;

	if (!data->stacks.b || !data->stacks.b->next)
		return ; // if there in only 1 element, there is nothing to do.
	temp1 = data->stacks.b; // address of first element
	temp2 = data->stacks.b->next->next; // address of third element
	data->stacks.b = data->stacks.b->next; // second element placed at the top
	data->stacks.b->next = temp1; // first element is placed after second
	temp1->next = temp2; // third element is placed after the first one
}

void	ss(t_malloc_stuff *data)
{
	sa(data);
	sb(data);
}

void	pa(t_malloc_stuff *data)
{
	t_nbr_list	*temp;

	if (!data->stacks.b)
		return ; // if b is emtpy, there is nothing to push
	temp = data->stacks.b->next; // second element of stack b
	data->stacks.b->next = data->stacks.a; // all stack a is now under the first element of stack b
	data->stacks.a = data->stacks.b; // the first element of stack b, + all the stack a, is now reattached to stack a pointer.
	data->stacks.b = temp; // stack b without its first element is reattached to stack b pointer
}

void	pb(t_malloc_stuff *data)
{
	t_nbr_list	*temp;

	if (!data->stacks.a)
		return ;
	temp = data->stacks.a->next;
	data->stacks.a->next = data->stacks.b;
	data->stacks.b = data->stacks.a;
	data->stacks.a = temp;
}
