/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 12:48:13 by ftassada          #+#    #+#             */
/*   Updated: 2021/04/21 11:47:32 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	right_ind(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	int		in_set;

	in_set = 1;
	i = ft_strlen(s1) - 1;
	while (i && in_set != 0)
	{
		j = 0;
		in_set = 0;
		while (set[j])
			if (set[j++] == s1[i])
				in_set = 1;
		if (in_set != 0)
			i--;
	}
	if (i == 0)
		return (0);
	return (i + 1);
}

static	size_t	left_ind(char const *s1, char const *set, size_t *ir, size_t *q)
{
	size_t	i;
	size_t	j;
	int		in_set;

	in_set = 1;
	i = 0;
	while (s1[i] && in_set != 0)
	{
		j = 0;
		in_set = 0;
		while (set[j])
			if (set[j++] == s1[i])
				in_set = 1;
		if (in_set != 0)
			i++;
	}
	if (i == ft_strlen(s1))
		i = 0;
	*ir = i;
	*q = right_ind(s1, set);
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	iremember;

	if (!s1)
		return (NULL);
	if (!set)
	{
		str = ft_calloc(ft_strlen(s1) + 1, sizeof(*str));
		if (!str)
			return (NULL);
		while (*s1)
			*str++ = *s1++;
		*str = '\0';
		return (str);
	}
	i = left_ind(s1, set, &iremember, &j);
	str = ft_calloc(j - i + 1, sizeof(*str));
	if (!str)
		return (NULL);
	while (i != j)
		*str++ = s1[i++];
	*str = '\0';
	return (str - (j - iremember));
}
