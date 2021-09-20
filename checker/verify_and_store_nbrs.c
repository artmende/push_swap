/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_and_store_nbrs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:39:41 by artmende          #+#    #+#             */
/*   Updated: 2021/09/20 16:59:07 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	store_numbers(int argc, char **argv, t_malloc_stuff *data)
{
	if (argc == 1)
		call_exit(0, 0, 0);
	else if (argc == 2)
		create_nbr_list_from_str(argv[1], data);
	else
		create_nbr_list_from_args(argc, argv, data);
}

void	check_number_from_args(char *str, t_nbr_list **nbr_list)
{
	// check that if there is a -, its at the first position
	// check that there is no other sign than nbr and -
	// check that the value is in range
	// if any error, free the linked list, display error and exit

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

void	check_number_from_str(char *str)
{

	// check that there are no wrong character
	// check that - is either the first character, or that - is followed by space

	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr("0123456789- ", str[i]) // wrong character in string
			|| (str[i] == '-' && i > 0 && str[i - 1] != ' ') // something like 5-5
			|| (str[i] == '-' && !str[i + 1]) // something like "5 -"
			|| (str[i] == '-' && !ft_strchr("0123456789", str[i + 1]))) // something like "5 - -5"
			call_exit(0, 0, 0);
		i++;
	}
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

void	create_nbr_list_from_args(int argc, char **argv, t_malloc_stuff *data)
{
	int	i;
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
		new->nbr = ft_atoi(argv[i], &data->stacks.a); // if wrong value, need to free the linked list
		verify_number_is_not_duplicate(ft_atoi(argv[i], &data->stacks.a),
			&data->stacks.a);
		i++;
	}
}

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
			while(*str && ft_strchr("0123456789-", *str))
				str++;
		}
		else
			str++;
	}
}
