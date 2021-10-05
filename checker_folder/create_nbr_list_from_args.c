/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_nbr_list_from_args.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:21:52 by artmende          #+#    #+#             */
/*   Updated: 2021/09/21 15:36:13 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
**	In the case where the numbers are received as argument of main, we verify
**	each arg to check if it only contain a valid number.
**
**	Possible errors that we look for are :
**	- wrong character in the string
**	- minus sign that is not at the front of the string
**	- minus sign with no number after it
**
**	We verify that the number is not out of range inside of ft_atoi.
*/

void	create_nbr_list_from_args(int argc, char **argv, t_malloc_stuff *data)
{
	int			i;
	t_nbr_list	*new;

	i = 1;
	while (i < argc)
	{
		check_number_from_args(argv[i], &data->stacks.a);
		new = malloc(sizeof(t_nbr_list));
		if (!new)
			call_exit(&data->stacks.a, 0, 0);
		ft_lstadd_back(&data->stacks.a, new);
		data->stacks.nbr_of_element++;
		new->nbr = ft_atoi(argv[i], &data->stacks.a);
		verify_number_is_not_duplicate(ft_atoi(argv[i], &data->stacks.a),
			&data->stacks.a);
		i++;
	}
}

void	check_number_from_args(char *str, t_nbr_list **nbr_list)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr("0123456789-", str[i])
			|| (str[i] == '-' && i > 0)
			|| (str[i] == '-' && !str[i + 1]))
			call_exit(nbr_list, 0, 0);
		i++;
	}
}
