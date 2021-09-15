/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 10:43:35 by artmende          #+#    #+#             */
/*   Updated: 2021/09/15 15:38:30 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
		return ;
	}
	while (s->next)
		s = s->next;
	s->next = new;
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

	t_stacks_a_b	stacks;

	ft_memset(&stacks, 0, sizeof(stacks));
//	t_nbr_list	*nbr_list;
//	nbr_list = 0;
	store_numbers(argc, argv, &stacks.a);



while(stacks.a)
{
	printf("%d\n", stacks.a->nbr);
	stacks.a = stacks.a->next;
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