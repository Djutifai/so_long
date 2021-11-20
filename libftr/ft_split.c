/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:38:45 by ftassada          #+#    #+#             */
/*   Updated: 2021/04/22 15:21:02 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_wordcounter(char const *str, char c)
{
	size_t	i;
	size_t	counter;
	size_t	flag;

	i = 0;
	counter = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i++] != c)
		{
			if (!flag)
			{
				counter++;
				flag = 1;
			}
		}
		else
			flag = 0;
	}
	return (counter);
}

static	char	*ft_strndup(const char *str, size_t n)
{
	size_t	strlen;
	char	*pstr;
	char	*temppstr;

	strlen = ft_strlen(str);
	if (n < strlen)
		strlen = n;
	pstr = ft_calloc(strlen + 1, sizeof(char));
	if (!pstr)
		return (NULL);
	temppstr = pstr;
	while (n-- && *str)
		*temppstr++ = *str++;
	*temppstr = '\0';
	return (pstr);
}

static	void	ft_freeall(char	**strings)
{
	size_t	i;

	i = 0;
	while (strings[i])
		free(strings[i++]);
	free (strings);
}

static	char	**ft_make_strings(char	**strings, char *str, int c)
{
	char	**firststring;
	size_t	counter;

	firststring = strings;
	while (*str)
	{
		counter = 0;
		while (*(str + counter) && *(str + counter) != c)
			counter++;
		if (0 < counter)
		{
			*strings = ft_strndup(str, counter);
			if (!*strings++)
			{
				ft_freeall(strings);
				return (NULL);
			}
			str += counter;
		}
		else
			str++;
	}
	return (firststring);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	size_t	wordcounter;

	if (!s)
		return (NULL);
	wordcounter = ft_wordcounter(s, c);
	strings = (char **)ft_calloc(wordcounter + 1, sizeof(*strings));
	if (!strings)
		return (NULL);
	strings = ft_make_strings(strings, (char *)s, c);
	return (strings);
}
