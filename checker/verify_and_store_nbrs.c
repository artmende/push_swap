/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_and_store_nbrs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:39:41 by artmende          #+#    #+#             */
/*   Updated: 2021/09/15 16:15:12 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	store_numbers(int argc, char **argv, t_nbr_list **nbr_list)
{
	if (argc == 1)
		return ;
	else if (argc == 2)
		create_nbr_list_from_str(argv[1], nbr_list);
	else
		create_nbr_list_from_args(argc, argv, nbr_list);
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
		if (!ft_strchr("0123456789-", str[i]) || (str[i] == '-' && i > 0))
		{
			
		}

		i++;
	}
}

void	create_nbr_list_from_args(int argc, char **argv, t_nbr_list **nbr_list)
{
	int	i;
	char	*str;
	t_nbr_list	*new;

	i = 1;
	while (i < argc)
	{
		str = argv[i];
		while (*str)
		{
			if (!ft_strchr("0123456789- ", *str) || (*str == '-' && !ft_strchr("0123456789", *(str + 1))))
			{
				write(1, "Error\n", 7);
				exit(0);
			}
			str++;
		}
		// check argv is correct !! detect -- and detect not number
		new = malloc(sizeof(t_nbr_list));
		if (!new)
		{
			//error! // need to free the linked list
		}
		new->nbr = ft_atoi(argv[i]); // if wrong value, need to free the linked list
		ft_lstadd_back(nbr_list, new);
		i++;
	}
}

void	create_nbr_list_from_str(char *str, t_nbr_list **nbr_list)
{
	t_nbr_list	*new;

	while (*str)
	{
		if (!ft_strchr("0123456789- ", *str) || (*str == '-' && !ft_strchr("0123456789", *(str + 1))))
		{
			// error
			write(1, "Error\n", 7);
			exit(0);
		}
		else if (ft_strchr("0123456789-", *str))
		{
			new = malloc(sizeof(t_nbr_list));
			if (!new)
			{
				//error !
			}
			new->nbr = ft_atoi(str);
			ft_lstadd_back(nbr_list, new);
			while(*str && ft_strchr("0123456789-", *str))
				str++;
		}
		else
			str++;
	}
}
