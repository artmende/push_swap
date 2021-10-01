/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_and_store_nbrs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:39:41 by artmende          #+#    #+#             */
/*   Updated: 2021/10/01 16:45:35 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	store_numbers(int argc, char **argv, t_stacks_a_b *stacks)
{
	if (argc == 1)
		return ;
	else if (argc == 2)
		create_nbr_list_from_str(argv[1], stacks);
	else
		create_nbr_list_from_args(argc, argv, stacks);
}

void	verify_number_is_not_duplicate(int nbr, t_nbr_list **nbr_list)
{
	t_nbr_list	*cursor;

	cursor = 0;
	if (nbr_list)
		cursor = *nbr_list;
	while (cursor)
	{
		if (nbr == cursor->nbr && cursor->next)
			call_exit(nbr_list, 0, 0);
		cursor = cursor->next;
	}
}
