/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:08:23 by artmende          #+#    #+#             */
/*   Updated: 2021/09/16 16:08:39 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

char	*ft_strnstr(char *str, char *to_find, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (to_find[0] == 0)
		return (str);
	while (str[i] && i < len)
	{
		if (str[i] == to_find[0])
		{
			while (str[i + j] == to_find[j] && i + j < len)
			{
				if (to_find[j + 1] == 0)
					return (&str[i]);
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (0);
}
