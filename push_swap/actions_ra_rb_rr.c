/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_ra_rb_rr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:43:56 by artmende          #+#    #+#             */
/*   Updated: 2021/09/22 15:10:51 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	ra : rotate stack A.
**	rb : rotate stack B.
**	rr : rotate stack A and stack B.
**	The first element becomes the last one.
*/

int	ra(t_stacks_a_b *stacks)
{
	t_nbr_list	*temp1;
	t_nbr_list	*temp2;

	if (!stacks->a || !stacks->a->next)
		return (0);
	temp1 = stacks->a->next;
	temp2 = temp1;
	while (temp2->next)
		temp2 = temp2->next;
	temp2->next = stacks->a;
	stacks->a->next = 0;
	stacks->a = temp1;
	return (0);
}

int	rb(t_stacks_a_b *stacks)
{
	t_nbr_list	*temp1;
	t_nbr_list	*temp2;

	if (!stacks->b || !stacks->b->next)
		return (0);
	temp1 = stacks->b->next;
	temp2 = temp1;
	while (temp2->next)
		temp2 = temp2->next;
	temp2->next = stacks->b;
	stacks->b->next = 0;
	stacks->b = temp1;
	return (0);
}

int	rr(t_stacks_a_b *stacks)
{
	ra(stacks);
	rb(stacks);
	return (0);
}
