/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 10:43:35 by artmende          #+#    #+#             */
/*   Updated: 2021/09/16 17:49:15 by artmende         ###   ########.fr       */
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


int	run_action(t_malloc_stuff *data)
{
	int	len;

	len = ft_len_nl(data->line, 0);
	if (!len && data->empty_line < 2)
	{
		data->empty_line++;
		return (0);
	}
	printf("About to evaluate data_empty_line. The value is : %d\n", data->empty_line);
	if (data->empty_line > 1)
		call_exit(&data->stacks.a, &data->stacks.b, data->line);
	else if (len == 2)
	{
		if (ft_strnstr("sa", data->line, 2))
			return (sa(data));
		else if (ft_strnstr("sb", data->line, 2))
			return (sb(data));
		else if (ft_strnstr("ss", data->line, 2))
			return (ss(data));
		else if (ft_strnstr("pa", data->line, 2))
			return (pa(data));
		else if (ft_strnstr("pb", data->line, 2))
			return (pb(data));
		else if (ft_strnstr("ra", data->line, 2))
			return (ra(data));
		else if (ft_strnstr("rb", data->line, 2))
			return (rb(data));
		else if (ft_strnstr("rr", data->line, 2))
			return (rr(data));
		else
			call_exit(&data->stacks.a, &data->stacks.b, data->line);
	}
	else if (len == 3)
	{
		if (ft_strnstr("rra", data->line, 3))
			return (rra(data));
		else if (ft_strnstr("rrb", data->line, 3))
			return (rrb(data));
		else if (ft_strnstr("rrr", data->line, 3))
			return (rrr(data));
		else
			call_exit(&data->stacks.a, &data->stacks.b, data->line);
	}
	else
		call_exit(&data->stacks.a, &data->stacks.b, data->line);
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
	int	gnl_return;

	t_malloc_stuff	stacks_line;
	ft_memset(&stacks_line, 0, sizeof(stacks_line));

	store_numbers(argc, argv, &stacks_line.stacks.a);

	t_nbr_list	*list_ptr;
	list_ptr = stacks_line.stacks.a;
	
write(1, "\nStack A before any instruction\n\n", 34);
while(list_ptr)
{
	printf("%d\n", list_ptr->nbr);
	list_ptr = list_ptr->next;
}
	write(1, "\n", 1);
	gnl_return = 1;

	while (gnl_return)
	{
		gnl_return = get_next_line(0, &stacks_line.line);
		if (gnl_return == -1)
			call_exit(&stacks_line.stacks.a, &stacks_line.stacks.b, 0);
		run_action(&stacks_line);
		free(stacks_line.line);
		// check if gnl_return is not -1
		// check if incorrect instruction
		// execute instruction
		// free line
	}

write(1, "\nStack A after following instructions\n\n", 40);
while(stacks_line.stacks.a)
{
	printf("%d\n", stacks_line.stacks.a->nbr);
	stacks_line.stacks.a = stacks_line.stacks.a->next;
}

printf("data_empty_line is : %d\n", stacks_line.empty_line);

	return (0);
}