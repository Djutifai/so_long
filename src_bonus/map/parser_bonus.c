/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 23:57:16 by ftassada          #+#    #+#             */
/*   Updated: 2022/01/11 00:31:09 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

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

static void	search_for_enemies(t_vars *vars, char *str, int j)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ENEMY)
		{
			vars->enemies[vars->cur_enemies - 1].x = i;
			vars->enemies[vars->cur_enemies - 1].y = j;
			vars->cur_enemies--;
		}
		i++;
	}
}

static char	**parse_map(int fd, t_vars *vars, int max_x, int max_y)
{
	char	**map;
	int		i;

	vars->max_x = max_x;
	vars->max_y = max_y;
	map = malloc(sizeof(*map) * max_y);
	vars->enemies = malloc(sizeof(t_enemy) * vars->cur_enemies);
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
		search_for_enemies(vars, map[i], i);
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
	val->enemy = 0;
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
	fd = open(file, O_RDONLY);
	if (check_if_square(fd, max_x, max_y) == -1)
		put_error(fd);
	fd = open(file, O_RDONLY);
	vars.cur_enemies = val->enemy;
	parse_map(fd, &vars, max_x, max_y);
	init_vars(&vars);
	vars.cur_enemies = val->enemy;
	vars.max_col = val->col;
	free(val);
	return (vars);
}
