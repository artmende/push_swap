/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:59:30 by artmende          #+#    #+#             */
/*   Updated: 2021/09/21 15:00:07 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	run_action(t_malloc_stuff *data)
{
	int	len;

	len = ft_len_nl(data->line, 0);
	if (len == 2)
		run_action_len_is_2(data);
	else if (len == 3)
		run_action_len_is_3(data);
	else
		call_exit(&data->stacks.a, &data->stacks.b, data->line);
	return (0);
}

int	run_action_len_is_2(t_malloc_stuff *data)
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
	return (0);
}

int	run_action_len_is_3(t_malloc_stuff *data)
{
	if (ft_strnstr("rra", data->line, 3))
		return (rra(data));
	else if (ft_strnstr("rrb", data->line, 3))
		return (rrb(data));
	else if (ft_strnstr("rrr", data->line, 3))
		return (rrr(data));
	else
		call_exit(&data->stacks.a, &data->stacks.b, data->line);
	return (0);
}
