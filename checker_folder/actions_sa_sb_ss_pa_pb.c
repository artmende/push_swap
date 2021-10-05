/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_sa_sb_ss_pa_pb.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:01:26 by artmende          #+#    #+#             */
/*   Updated: 2021/09/21 15:12:25 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
**	sa : swap the first 2 elements of stack A.
**	sb : swap the first 2 elements of stack B.
**	ss : swap the first 2 elements of stack A and stack B.
**	pa : the first element of stack B is pushed to the top of stack A.
**	pb : the first element of stack A is pushed to the top of stack B.
*/

int	sa(t_malloc_stuff *data)
{
	t_nbr_list	*temp1;
	t_nbr_list	*temp2;

	if (!data->stacks.a || !data->stacks.a->next)
		return (0);
	temp1 = data->stacks.a;
	temp2 = data->stacks.a->next->next;
	data->stacks.a = data->stacks.a->next;
	data->stacks.a->next = temp1;
	temp1->next = temp2;
	return (0);
}

int	sb(t_malloc_stuff *data)
{
	t_nbr_list	*temp1;
	t_nbr_list	*temp2;

	if (!data->stacks.b || !data->stacks.b->next)
		return (0);
	temp1 = data->stacks.b;
	temp2 = data->stacks.b->next->next;
	data->stacks.b = data->stacks.b->next;
	data->stacks.b->next = temp1;
	temp1->next = temp2;
	return (0);
}

int	ss(t_malloc_stuff *data)
{
	sa(data);
	sb(data);
	return (0);
}

int	pa(t_malloc_stuff *data)
{
	t_nbr_list	*temp;

	if (!data->stacks.b)
		return (0);
	temp = data->stacks.b->next;
	data->stacks.b->next = data->stacks.a;
	data->stacks.a = data->stacks.b;
	data->stacks.b = temp;
	return (0);
}

int	pb(t_malloc_stuff *data)
{
	t_nbr_list	*temp;

	if (!data->stacks.a)
		return (0);
	temp = data->stacks.a->next;
	data->stacks.a->next = data->stacks.b;
	data->stacks.b = data->stacks.a;
	data->stacks.a = temp;
	return (0);
}
