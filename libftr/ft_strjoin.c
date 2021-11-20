/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:33:59 by ftassada          #+#    #+#             */
/*   Updated: 2021/04/20 13:12:35 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1len;
	size_t	s2len;

	s1len = 0;
	s2len = 0;
	if (s1)
		s1len = ft_strlen(s1);
	if (s2)
		s2len = ft_strlen(s2);
	str = (char *)ft_calloc(s1len + s2len + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (s1len > 0)
		while (*s1)
			*str++ = *s1++;
	if (s2len > 0)
		while (*s2)
			*str++ = *s2++;
	*str = '\0';
	return (str - s1len - s2len);
}
