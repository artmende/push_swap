/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 09:47:14 by artmende          #+#    #+#             */
/*   Updated: 2021/09/14 14:53:07 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

static unsigned int	nbr_elem(const char *s, char c, int f)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && f != 1)
			i++;
		if (s[i])
			j++;
		while (s[i] != c && s[i])
			i++;
		if (s[i] == c && f == 1)
			break ;
	}
	if (f == 1)
		j = i;
	return (j);
}

static int			write_str(char *dest, const char *src, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (i);
}

static char			**nulfree(char **res, unsigned int j)
{
	unsigned int	i;

	i = 0;
	while (i < j)
	{
		free(res[j]);
		i++;
	}
	free(res);
	return (0);
}

char				**ft_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	char			**res;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	res = (char **)malloc(sizeof(res) * (nbr_elem(s, c, 0) + 1));
	if (!res)
		return (0);
	while (j < nbr_elem(s, c, 0) && nbr_elem(s, c, 0))
	{
		while (s[i] == c)
			i++;
		res[j] = (char *)malloc(sizeof(char) * (1 + nbr_elem(&s[i], c, 1)));
		if (!res[j])
			return (nulfree(res, j));
		i = i + write_str(res[j], &s[i], nbr_elem(&s[i], c, 1));
		j++;
	}
	res[j] = 0;
	return (res);
}
