/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:32:20 by artmende          #+#    #+#             */
/*   Updated: 2021/09/22 14:32:39 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	c_e;
	unsigned char	*edit;

	c_e = (unsigned char)c;
	edit = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		edit[i] = c_e;
		i++;
	}
	return (s);
}
