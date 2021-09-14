/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:00:27 by artmende          #+#    #+#             */
/*   Updated: 2021/09/14 15:01:19 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

/*
	ft_atoi has been modified a little bit to fit the norm v3 of 42 school.
	In case of a number outside of the range of a long int, the function is
	supposed to return 0 or -1.
	It has been set to always return -1 in such a case. It is safe to do so in
	this project.
*/

int	ft_atoi(const char *str)
{
	int			i;
	int			j;
	int			minus;
	long int	result_l;

	i = 0;
	j = 0;
	minus = 1;
	result_l = 0;
	while (str[j] == ' ' || (str[j] >= 9 && str[j] <= 13))
		j++;
	if (str[i + j] == '-' || str[i + j] == '+')
	{
		if (str[i + j] == '-')
			minus = minus - 2;
		i++;
	}
	while (str[i + j] >= '0' && str[i + j] <= '9')
	{
		result_l = 10 * result_l + str[i + j] - '0';
		if (result_l < 0 || (i > 18 && minus == 1) || (i > 19 && minus == -1))
			return (-1);
		i++;
	}
	return ((int)(minus * result_l));
}
