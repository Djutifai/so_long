/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:54:12 by ftassada          #+#    #+#             */
/*   Updated: 2021/04/21 13:12:25 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_putnbr(int n, int fd)
{
	char	divdigit;

	if (n < 0)
	{
		write(fd, "-", 1);
		if (n == -2147483648)
		{
			write(fd, "2", 1);
			ft_putnbr(147483648, fd);
		}
		n *= (-1);
	}
	if (n >= 10)
	{
		divdigit = (n % 10) + 48;
		n = n / 10;
		ft_putnbr(n, fd);
		write(fd, &divdigit, 1);
	}
	else if (n >= 0 && n <= 9)
	{
		divdigit = n + 48;
		write(fd, &divdigit, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	ft_putnbr(n, fd);
}
