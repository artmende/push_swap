/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_rra_rrb_rrr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:26:29 by artmende          #+#    #+#             */
/*   Updated: 2021/09/21 15:34:46 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
**	rra : inverse rotation of stack A.
**	rrb : inverse rotation of stack B.
**	rrr : inverse rotation of stack A and stack B.
**	The last element becomes the first one.
*/

int	rra(t_malloc_stuff *data)
{
	t_nbr_list	*temp1;
	t_nbr_list	*temp2;

	if (!data->stacks.a || !data->stacks.a->next)
		return (0);
	temp1 = data->stacks.a;
	while (temp1->next->next)
		temp1 = temp1->next;
	temp2 = temp1->next;
	temp1->next = 0;
	temp2->next = data->stacks.a;
	data->stacks.a = temp2;
	return (0);
}

int	rrb(t_malloc_stuff *data)
{
	t_nbr_list	*temp1;
	t_nbr_list	*temp2;

	if (!data->stacks.b || !data->stacks.b->next)
		return (0);
	temp1 = data->stacks.b;
	while (temp1->next->next)
		temp1 = temp1->next;
	temp2 = temp1->next;
	temp1->next = 0;
	temp2->next = data->stacks.b;
	data->stacks.b = temp2;
	return (0);
}

int	rrr(t_malloc_stuff *data)
{
	rra(data);
	rrb(data);
	return (0);
}
