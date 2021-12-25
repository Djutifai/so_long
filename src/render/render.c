/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 22:30:30 by ftassada          #+#    #+#             */
/*   Updated: 2021/12/25 02:02:27 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static char	*ft_put_moves(t_vars *vars)
{
	char	*move;
	char	*res;
	char	*left_str;

	left_str = ft_strdup("Amount of moves: ");
	move = ft_itoa(vars->moves);
	res = ft_strjoin(left_str, move);
	mlx_string_put(vars->mlx, vars->win, 0, 15, \
		0 << 24 | 255 << 16 | 255 << 8 | 0, res);
	ft_putstr_fd(res, 1);
	write(1, "\n", 1);
	free(res);
	free(move);
	return (res);
}

static void	put_img(t_vars *vars, int i, int j)
{
	void	*img;

	if (vars->map[j][i] == WALL)
		img = vars->sprites.wall;
	else if (vars->map[j][i] == PLAYER)
		img = vars->sprites.hero;
	else if (vars->map[j][i] == COLLECTIBLE)
		img = vars->sprites.pnsh;
	else if (vars->map[j][i] == EXIT)
		img = vars->sprites.adm;
	else
		img = vars->sprites.floor;
	if (vars->map[j][i] == 'P' || vars->map[j][i] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, \
			vars->sprites.floor, i * 25, j * 25);
	mlx_put_image_to_window(vars->mlx, vars->win, img, i * 25, j * 25);
}

static void	draw_map(t_vars *vars, int j, int map_j)
{
	int	i;
	int	map_i;

	while (j < vars->heigth)
	{
		i = 0;
		map_i = 0;
		if (vars->hero_x - 5 > 0)
		{
			i = vars->hero_x * 25 - 5 * 25;
			map_i = vars->hero_x - 5;
		}
		while (i < vars->width)
		{
			printf("%d %d\n",map_i, map_j);
			printf("%d %d\n",vars->max_x, vars->max_y);
			put_img(vars, map_i, map_j);
			map_i++;
			i += 25;
		}
		map_j++;
		j += 25;
	}
}

void	render_big(t_vars *vars)
{
	int		j;
	int		map_j;

	j = 0;
	map_j = 0;
	if (vars->hero_y - 5 > 0)
	{
		j = vars->hero_y * 25 - 5 * 25;
		map_j = vars->hero_y - 5;
	}
	draw_map(vars, j, map_j);
	ft_put_moves(vars);
}

void	render(t_vars *vars)
{
	int		j;
	int		map_j;

	j = 0;
	map_j = 0;
	draw_map(vars, j, map_j);
	ft_put_moves(vars);
}
