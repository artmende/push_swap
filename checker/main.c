/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 10:43:35 by artmende          #+#    #+#             */
/*   Updated: 2021/09/15 11:44:27 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>


void	ft_lstadd_back(t_number_list **alst, t_number_list *new)
{
	t_number_list	*s;

	if (!new || !alst)
		return ;
	s = *alst;
	new->next = 0;
	if (!s)
	{
		*alst = new;
		return ;
	}
	while (s->next)
		s = s->next;
	s->next = new;
}




void	create_nbr_list_from_str(char *str, t_number_list **number_list)
{
	t_number_list	*new;

	while (*str)
	{
		if (!ft_strchr("0123456789- ", *str) || (*str == '-' && !ft_strchr("0123456789", *(str + 1))))
		{
			// error
			write(1, "error\n", 6);
			exit(0);
		}
		else if (ft_strchr("0123456789-", *str))
		{
			new = malloc(sizeof(t_number_list));
			if (!new)
			{
				//error !
			}
			new->nbr = ft_atoi(str);
			ft_lstadd_back(number_list, new);
			while(*str && ft_strchr("0123456789-", *str))
				str++;
		}
		else
			str++;
	}
}

void	create_nbr_list_from_args(int argc, char **argv, t_number_list **number_list)
{
	int	i;
	t_number_list	*new;

	i = 1;
	while (i < argc)
	{
		// check argv is correct
		new = malloc(sizeof(t_number_list));
		if (!new)
		{
			//error!
		}
		new->nbr = ft_atoi(argv[i]);
		ft_lstadd_back(number_list, new);
		i++;
	}
}

void	verify_input_str(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (ft_strchr("0123456789", *str))
		{
			while (*(str + i) && ft_strchr("0123456789", *(str + i)))
				i++;
			printf("Inside the loop : %d\n", ft_atoi(str));
			if (i > 10 || (i == 10 && *str > '2') || (*(str - 1) == '-'
				&& ft_atoi(str - 1) > 0) || (*(str - 1) != '-'
				&& ft_atoi(str) < 0))
			{
				write(1, "Error, nbr out of range\n", 25);
				exit(0);
			}
			str = str + i;
			i = 0;
		}
		else
			str++;
	}
}

void	store_numbers(int argc, char **argv, t_number_list **number_list)
{
	if (argc == 1)
	{
		// error
		printf("%s\n", "argc = 1");
	}
	if (argc == 2)
	{
		printf("%s\n", "argc = 2");
		printf("things to save : %s\n", argv[1]);
		verify_input_str(argv[1]);
		create_nbr_list_from_str(argv[1], number_list);
	}
	else
	{
		printf("%s\n", "argc est superieur a 2");
		// fill linked list
		create_nbr_list_from_args(argc, argv, number_list);
	}

}


int	main(int argc, char **argv)
{
	// verify input for errors
	
	// 1) store all numbers in the linked list
	// 2) store all instruction in a array (read 0)
	// 3) apply each instruction to the linked list
		// code function for each type of instruction
	// 4) verify that the linked list is now sorted, display OK if yes

//	write(1, "coucou\n", 7);
//	printf("argc is : %d\n", argc);
	(void)argv;
	(void)argc;

//	char	*line = 0;
//	int	gnl_return = 0;

	t_number_list	*number_list;
	number_list = 0;
	store_numbers(argc, argv, &number_list);

while(number_list)
{
	printf("%d\n", number_list->nbr);
	number_list = number_list->next;
}


/* 	while(1)
	{
		gnl_return = get_next_line(0, &line);
		printf("gnl_return is : %d\n", gnl_return);
		printf("%s\n", line);
		if (!gnl_return)
			break ;
	} */

	return (0);
}