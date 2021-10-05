/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 10:43:35 by artmende          #+#    #+#             */
/*   Updated: 2021/10/02 11:53:32 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
**	The checker works that way :
**
**	Stacks A and B are each a linked list, with the top of the stack being the
**	first element of the list.
**	We first store all numbers in stack A.
**	While doing so, we verify that there are no errors, like out of range
**	numbers, or duplicates, or wrong character in the input string / args.
**
**	Depending on how the checker is called, the input might be received as a
**	string with all numbers separated by spaces, or each number might be a
**	separate argument of main.
**
**	After all numbers are stored in stack A, the instructions are read 1 line at
**	a time using get_next_line.
**	For each line read, we verify that the instruction is correct, and we
**	execute the associated action.
**
**	After all instructions have been read, we verify that the stack A is now
**	sorted and complete.
**
**	For convenience in avoiding memory leaks, all heap pointers are kept in a
**	single structure.
*/

int	main(int argc, char **argv)
{
	t_malloc_stuff	stacks_line;

	if (argc == 1)
		return (0);
	ft_memset(&stacks_line, 0, sizeof(stacks_line));
	store_numbers(argc, argv, &stacks_line);
	reading_instructions_loop(&stacks_line);
	verify_stack_a_is_sorted(&stacks_line);
	return (0);
}

void	reading_instructions_loop(t_malloc_stuff *data)
{
	int	gnl_return;

	gnl_return = 1;
	while (gnl_return)
	{
		gnl_return = get_next_line(0, &data->line);
		if (gnl_return == -1)
			call_exit(&data->stacks.a, &data->stacks.b, 0);
		if (gnl_return == 0 && ft_len_nl(data->line, 0))
			call_exit(&data->stacks.a, &data->stacks.b, data->line);
		if (gnl_return == 0 && !ft_len_nl(data->line, 0))
		{
			free(data->line);
			break ;
		}
		run_action(data);
		free(data->line);
	}
	data->line = 0;
}

void	verify_stack_a_is_sorted(t_malloc_stuff *data)
{
	t_nbr_list	*list_ptr;

	list_ptr = data->stacks.a;
	while (data->stacks.a && list_ptr->next)
	{
		if (list_ptr->nbr > list_ptr->next->nbr)
			break ;
		data->stacks.nbr_of_element--;
		list_ptr = list_ptr->next;
	}
	if (!data->stacks.a || data->stacks.nbr_of_element != 1)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free_linked_list(&data->stacks.a);
	free_linked_list(&data->stacks.b);
}

int	call_exit(t_nbr_list **stack_a, t_nbr_list **stack_b, char *line)
{
	free_linked_list(stack_a);
	free_linked_list(stack_b);
	free(line);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
	return (0);
}
