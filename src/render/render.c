/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 22:30:30 by ftassada          #+#    #+#             */
/*   Updated: 2021/12/25 19:24:12 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	draw_map(t_vars *vars, int j, int map_j)
{
	int	i;
	int	map_i;

	while (j < vars->heigth)
	{
		i = 0;
		map_i = 0;
		if (vars->hero_x - vars->vision > 0)
		{
			i = vars->hero_x * FRAME - vars->vision * FRAME;
			map_i = vars->hero_x - vars->vision;
		}
		while (i < vars->width)
		{
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
	if (vars->hero_y - vars->vision > 0)
	{
		j = vars->hero_y * FRAME - vars->vision * FRAME;
		map_j = vars->hero_y - vars->vision;
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
