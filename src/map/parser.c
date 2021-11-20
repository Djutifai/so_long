/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 23:57:16 by ftassada          #+#    #+#             */
/*   Updated: 2021/11/09 22:11:22 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static t_val	*init_val(void)
{
	t_val	*val;

	val = malloc(sizeof(*val));
	if (val == NULL)
		put_error(0);
	val->col = 0;
	val->floor = 0;
	val->exit = 0;
	val->player = 0;
	val->wall = 0;
	val->symbols = 0;
	return (val);
}

void	parse_this(char *file)
{
	//char	**map;
	int		fd;
	int		max_x;
	int		max_y;
	t_val	*val;

	max_x = 0;
	max_y = 0;
	val = init_val();
	fd = open(file, O_RDONLY);
	validate_map(fd, &max_x, &max_y, val);
	close(fd);
	fd = open(file, O_RDONLY);
	if (check_if_square(fd, max_x, max_y) == -1)
		put_error(fd);
	close(fd);
	fd = open(file, O_RDONLY);
//	map = parse_map(fd);
	close(fd);
}
