/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 23:57:16 by ftassada          #+#    #+#             */
/*   Updated: 2022/01/10 23:38:07 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	search_for_player(t_vars *vars, char *str, int j)
{
	static int	found;
	int			i;

	i = 0;
	if (found == 1)
		return ;
	else
		found = 0;
	while (str[i] && str[i] != PLAYER)
		i++;
	if (str[i] == PLAYER)
	{
		vars->hero_x = i;
		vars->hero_y = j;
		found = 1;
	}
}

static char	**parse_map(int fd, t_vars *vars, int max_x, int max_y)
{
	char	**map;
	int		i;

	vars->max_x = max_x;
	vars->max_y = max_y;
	map = malloc(sizeof(*map) * max_y);
	if (!map)
		put_error(fd);
	i = 0;
	while (i < max_y)
	{
		get_next_line(fd, &map[i]);
		if (!map[i])
			free_map(&map, i, 1, fd);
		map[i][max_x] = '\0';
		search_for_player(vars, map[i], i);
		i++;
	}
	vars->map = map;
	close(fd);
	return (map);
}

static t_val	*init_val(void)
{
	t_val	*val;

	val = ft_calloc(sizeof(*val), 1);
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

t_vars	parse_this(char *file)
{
	int		fd;
	int		max_x;
	int		max_y;
	t_val	*val;
	t_vars	vars;

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
	parse_map(fd, &vars, max_x, max_y);
	init_vars(&vars);
	vars.max_col = val->col;
	close(fd);
	free(val);
	return (vars);
}
