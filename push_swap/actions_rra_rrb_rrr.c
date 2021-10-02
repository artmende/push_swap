/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_rra_rrb_rrr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:26:29 by artmende          #+#    #+#             */
/*   Updated: 2021/10/02 10:33:57 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	rra : inverse rotation of stack A.
**	rrb : inverse rotation of stack B.
**	rrr : inverse rotation of stack A and stack B.
**	The last element becomes the first one.
*/

int	rra(t_stacks_a_b *stacks)
{
	t_nbr_list	*temp1;
	t_nbr_list	*temp2;

	if (!stacks->a || !stacks->a->next)
		return (0);
	temp1 = stacks->a;
	while (temp1->next->next)
		temp1 = temp1->next; // temp1 is now avant dernier element
	temp2 = temp1->next; // temps2 is the last element
	temp1->next = 0;
	temp2->next = stacks->a;
	stacks->a = temp2;
	return (0);
}

int	rrb(t_stacks_a_b *stacks)
{
	t_nbr_list	*temp1;
	t_nbr_list	*temp2;

	if (!stacks->b || !stacks->b->next)
		return (0);
	temp1 = stacks->b;
	while (temp1->next->next)
		temp1 = temp1->next;
	temp2 = temp1->next;
	temp1->next = 0;
	temp2->next = stacks->b;
	stacks->b = temp2;
	return (0);
}

int	rrr(t_stacks_a_b *stacks)
{
	rra(stacks);
	rrb(stacks);
	return (0);
}
