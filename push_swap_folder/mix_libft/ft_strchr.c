/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:38:30 by artmende          #+#    #+#             */
/*   Updated: 2021/09/22 14:32:40 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	c_e;
	char	*s_e;

	c_e = (char)c;
	s_e = (char *)s;
	i = 0;
	while (s[i])
	{
		if (s[i] == c_e)
			return (&s_e[i]);
		i++;
	}
	if (c == 0)
		return (&s_e[i]);
	return (0);
}
