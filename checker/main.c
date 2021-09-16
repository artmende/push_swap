/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 10:43:35 by artmende          #+#    #+#             */
/*   Updated: 2021/09/16 11:00:45 by artmende         ###   ########.fr       */
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

int	call_exit(t_nbr_list **stack_a, t_nbr_list **stack_b, char *line)
{
	// free stack a
	// free stack b
	// free line
	// display error
	// exit

	free_linked_list(stack_a);
	free_linked_list(stack_b);
	free(line);
	write(2, "Error\n", 7);
	exit(EXIT_FAILURE);
	return (0);
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

	t_malloc_stuff	stacks_line;
	ft_memset(&stacks_line, 0, sizeof(stacks_line));

	store_numbers(argc, argv, &stacks_line.stacks.a);

write(1, "\nStack A before any instruction\n\n", 33);
while(stacks_line.stacks.a)
{
	printf("%d\n", stacks_line.stacks.a->nbr);
	stacks_line.stacks.a = stacks_line.stacks.a->next;
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