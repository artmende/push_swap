/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_ra_rb_rr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:43:56 by artmende          #+#    #+#             */
/*   Updated: 2021/09/21 15:06:28 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
**	ra : rotate stack A.
**	rb : rotate stack B.
**	rr : rotate stack A and stack B.
**	The first element becomes the last one.
*/

int	ra(t_malloc_stuff *data)
{
	t_nbr_list	*temp1;
	t_nbr_list	*temp2;

	if (!data->stacks.a || !data->stacks.a->next)
		return (0);
	temp1 = data->stacks.a->next;
	temp2 = temp1;
	while (temp2->next)
		temp2 = temp2->next;
	temp2->next = data->stacks.a;
	data->stacks.a->next = 0;
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
