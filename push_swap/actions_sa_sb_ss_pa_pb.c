/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_sa_sb_ss_pa_pb.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:01:26 by artmende          #+#    #+#             */
/*   Updated: 2021/10/02 10:32:55 by artmende         ###   ########.fr       */
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
	temp1 = stacks->a;
	temp2 = stacks->a->next->next;
	stacks->a = stacks->a->next;
	stacks->a->next = temp1;
	temp1->next = temp2;
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
	stacks->b->next = temp1;
	temp1->next = temp2;
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
	temp = stacks->b->next;
	stacks->b->next = stacks->a;
	stacks->a = stacks->b;
	stacks->b = temp;
	return (0);
}

int	pb(t_stacks_a_b *stacks)
{
	t_nbr_list	*temp;

	if (!stacks->a)
		return (0);
	temp = stacks->a->next;
	stacks->a->next = stacks->b;
	stacks->b = stacks->a;
	stacks->a = temp;
	return (0);
}
