/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 15:26:58 by ftassada          #+#    #+#             */
/*   Updated: 2021/11/10 00:19:33 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static int	square_helper(char *str, int max_x)
{
	int	i;

	i = 0;
	while (i != max_x)
		if (str[i++] != WALL)
			return (-1);
	i = ft_strlen(str) - max_x - 1;
	while (str[i] && str[i] != '\n')
		if (str[i++] != WALL)
			return (-1);
	return (1);
}

int	check_if_square(int fd, int max_x, int symbols)
{
	char	*str;

	str = malloc(sizeof(*str) * symbols + 1);
	if (!str)
		return (-1);
	read(fd, str, symbols);
	printf("a\n");
	if (square_helper(str, max_x) == -1)
	{
	printf("\n");
		free(str);
		put_error(fd);
	}
	printf("A\n");
	free(str);
	return (1);
}

static int	validate_values(t_val *val)
{
	if (val->col == 0 || val->exit == 0 || val->floor == 0 || \
		val->wall == 0 || val->player == 0 || val->player > 1)
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
}
