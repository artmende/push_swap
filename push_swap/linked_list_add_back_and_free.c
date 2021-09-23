/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_add_back_and_free.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:03:01 by artmende          #+#    #+#             */
/*   Updated: 2021/09/23 11:52:51 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_nbr_list **alst, t_nbr_list *new)
{
	t_nbr_list	*s;

	if (!new || !alst)
		return ;
	s = *alst;
	new->next = 0;
	if (!s)
	{
		*alst = new;
		new->previous = 0;
		return ;
	}
	while (s->next)
		s = s->next;
	s->next = new;
	new->previous = s;
}

void	free_linked_list(t_nbr_list **alst)
{
	t_nbr_list	*temp1;
	t_nbr_list	*temp2;

	temp1 = 0;
	if (alst)
		temp1 = *alst;
	while (temp1)
	{
		temp2 = temp1->next;
		free(temp1);
		temp1 = temp2;
	}
	if (alst)
		*alst = 0;
}
