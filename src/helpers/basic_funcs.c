/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:08:44 by ftassada          #+#    #+#             */
/*   Updated: 2021/11/09 01:18:22 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	check_format(char *file)
{
	size_t	i;

	i = ft_strlen(file);
	if (file[i - 1] == 'r' && file[i - 2] == 'e' && file[i - 3] == 'b' \
		&& file[i - 4] == '.')
		return (1);
	return (0);
}

void	put_error(int fd)
{
	if (fd != 0)
		close(fd);
	ft_putstr_fd("Error\n", 1);
	exit(1);
}
