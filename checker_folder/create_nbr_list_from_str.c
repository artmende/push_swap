/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_nbr_list_from_str.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:15:09 by artmende          #+#    #+#             */
/*   Updated: 2021/10/05 16:39:47 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	create_nbr_list_from_str(char *str, t_malloc_stuff *data)
{
	t_nbr_list	*new;

	check_number_from_str(str);
	while (*str)
	{
		if (ft_strchr("0123456789-", *str))
		{
			new = malloc(sizeof(t_nbr_list));
			if (!new)
				call_exit(&data->stacks.a, 0, 0);
			ft_lstadd_back(&data->stacks.a, new);
			data->stacks.nbr_of_element++;
			new->nbr = ft_atoi(str, &data->stacks.a);
			verify_number_is_not_duplicate(ft_atoi(str, &data->stacks.a),
				&data->stacks.a);
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
	int	detect_nbr;

	i = 0;
	detect_nbr = 0;
	while (str[i])
	{
		if (str[i] && ft_strchr("0123456789", str[i]))
			detect_nbr++;
		if (!ft_strchr("0123456789- ", str[i])
			|| (str[i] == '-' && i > 0 && str[i - 1] != ' ')
			|| (str[i] == '-' && !str[i + 1])
			|| (str[i] == '-' && !ft_strchr("0123456789", str[i + 1])))
			call_exit(0, 0, 0);
		i++;
	}
	if (!detect_nbr)
		call_exit(0, 0, 0);
}
