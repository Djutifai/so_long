/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:27:58 by ftassada          #+#    #+#             */
/*   Updated: 2021/04/21 11:47:38 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;
	size_t	res;
	int		islonger;

	islonger = 1;
	if (dstsize <= ft_strlen(dst))
		islonger = 0;
	dstlen = ft_strlen(dst);
	if (dstlen > dstsize)
		res = dstsize + ft_strlen(src);
	else
		res = dstlen + ft_strlen(src);
	i = 0;
	if (dstsize != 0)
		dstsize -= 1;
	while (dstlen < dstsize && src[i])
	{
		dst[dstlen] = src[i];
		dstlen++;
		i++;
	}
	if (dstsize != 0 && islonger != 0)
		dst[dstlen] = '\0';
	return (res);
}
