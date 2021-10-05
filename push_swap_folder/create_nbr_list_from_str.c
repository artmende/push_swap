/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_nbr_list_from_str.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:15:09 by artmende          #+#    #+#             */
/*   Updated: 2021/10/02 11:28:07 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	In the case where the numbers are received in a string, separated by spaces,
**	we first check the string to verify that we only have valid numbers.
**
**	Possible errors that we look for are :
**	- wrong character in the string
**	- something like "5-5"
**	- something like "5 -" (minus sign is at the end of the string)
**	- something like "5 - -5"
**
**	We verify that the number is not out of range inside of ft_atoi.
*/

void	create_nbr_list_from_str(char *str, t_stacks_a_b *stacks)
{
	t_nbr_list	*new;

	check_number_from_str(str);
	while (*str)
	{
		if (ft_strchr("0123456789-", *str))
		{
			new = malloc(sizeof(t_nbr_list));
			if (!new)
				call_exit(&stacks->a);
			ft_lstadd_back(&stacks->a, new);
			stacks->nbr_of_element++;
			new->nbr = ft_atoi(str, &stacks->a);
			verify_number_is_not_duplicate(ft_atoi(str, &stacks->a),
				&stacks->a);
			while (*str && ft_strchr("0123456789-", *str))
				str++;
		}
		else
			str++;
	}
}

void	check_number_from_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr("0123456789- ", str[i])
			|| (str[i] == '-' && i > 0 && str[i - 1] != ' ')
			|| (str[i] == '-' && !str[i + 1])
			|| (str[i] == '-' && !ft_strchr("0123456789", str[i + 1])))
			call_exit(0);
		i++;
	}
}
