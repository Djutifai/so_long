/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 15:26:58 by ftassada          #+#    #+#             */
/*   Updated: 2022/01/09 22:46:35 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

static int	square_helper(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
	{
		if (str[i++] != WALL)
			return (-1);
	}
	i = ft_strlen(str) - 1;
	while (str[i] != '\n')
		if (str[i--] != WALL)
			return (-1);
	return (1);
}

int	check_if_square(int fd, int max_x, int max_y)
{
	char	*str;
	int		size_of_map;

	size_of_map = max_x * max_y + max_y;
	str = ft_calloc(sizeof(*str), size_of_map);
	if (!str)
		return (-1);
	read(fd, str, size_of_map);
	str[size_of_map] = '\0';
	if (square_helper(str) == -1)
	{
		free(str);
		put_error(fd);
	}
	free(str);
	close(fd);
	return (1);
}

static int	validate_values(t_val *val)
{
	if (val->col == 0 || val->exit == 0 || \
		val->wall == 0 || val->player == 0 || val->player == 0)
		return (-1);
	return (0);
}

static int	validate_line(char *str, t_val *val)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == WALL)
			val->wall += 1;
		else if (str[i] == FLOOR)
			val->floor += 1;
		else if (str[i] == COLLECTIBLE)
			val->col += 1;
		else if (str[i] == EXIT)
			val->exit += 1;
		else if (str[i] == PLAYER)
			val->player += 1;
		else if (str[i] == ENEMY)
			val->enemy += 1;
		else
			return (-1);
		i++;
	}
	if (i != 0 && str[0] != WALL && str[i - 1] != WALL)
		return (-1);
	return (i);
}

void	validate_map(int fd, int *max_x, int *max_y, t_val *val)
{
	int		rd;
	char	*line;

	rd = get_next_line(fd, &line);
	*max_x = validate_line(line, val);
	free(line);
	if (*max_x == -1)
		put_error(fd);
	while (rd > 0)
	{
		rd = get_next_line(fd, &line);
		*max_y += 1;
		if (validate_line(line, val) != *max_x && rd > 0)
		{
			free(line);
			put_error(fd);
		}
		val->symbols += ft_strlen(line);
		free(line);
	}
	if (validate_values(val) == -1)
		put_error(fd);
	close(fd);
}
