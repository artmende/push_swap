/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_sa_sb_ss_pa_pb.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:01:26 by artmende          #+#    #+#             */
/*   Updated: 2021/09/23 13:00:20 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	sa : swap the first 2 elements of stack A.
**	sb : swap the first 2 elements of stack B.
**	ss : swap the first 2 elements of stack A and stack B.
**	pa : the first element of stack B is pushed to the top of stack A.
**	pb : the first element of stack A is pushed to the top of stack B.
*/

int	sa(t_stacks_a_b *stacks)
{
	t_nbr_list	*temp1;
	t_nbr_list	*temp2;

	if (!stacks->a || !stacks->a->next)
		return (0);
	temp1 = stacks->a; // temp1 is the first element that will become second
	temp2 = stacks->a->next->next; // temp2 is the 3rd element that we have to reconnect
	stacks->a = stacks->a->next;
	stacks->a->previous = 0; //
	temp1->previous = stacks->a; //
	stacks->a->next = temp1;
	temp1->next = temp2;
	temp2->previous = temp1; //
	return (0);
}

int	sb(t_stacks_a_b *stacks)
{
	t_nbr_list	*temp1;
	t_nbr_list	*temp2;

	if (!stacks->b || !stacks->b->next)
		return (0);
	temp1 = stacks->b;
	temp2 = stacks->b->next->next;
	stacks->b = stacks->b->next;
	stacks->b->previous = 0; //
	temp1->previous = stacks->b; //
	stacks->b->next = temp1;
	temp1->next = temp2;
	temp2->previous = temp1; //
	return (0);
}

int	ss(t_stacks_a_b *stacks)
{
	sa(stacks);
	sb(stacks);
	return (0);
}

int	pa(t_stacks_a_b *stacks)
{
	t_nbr_list	*temp;

	if (!stacks->b)
		return (0);
	temp = stacks->b->next; // temp is the new first element of stack B (might be 0)
	stacks->b->next = stacks->a; // this might be 0 if there was nothing in stacks a
	// stacks->b->previous was 0, because it was the first element of stack b, we dont need to change that
	// but we need to change the previous of the old first element of stack a, IF it exists
	if (stacks->a) //
		stacks->a->previous = stacks->b; //
	stacks->a = stacks->b;
	stacks->b = temp;
	if (stacks->b) //
		stacks->b->previous = 0; //
	return (0);
}

int	pb(t_stacks_a_b *stacks)
{
	t_nbr_list	*temp;

	if (!stacks->a)
		return (0);
	temp = stacks->a->next;
	stacks->a->next = stacks->b;
	if (stacks->b) //
		stacks->b->previous = stacks->a; //
	stacks->b = stacks->a;
	stacks->a = temp;
	if (stacks->a) //
		stacks->a->previous = 0;
	return (0);
}
