/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 22:30:30 by ftassada          #+#    #+#             */
/*   Updated: 2022/01/10 23:49:35 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_bonus.h"

static void	draw_map(t_vars *vars, t_cord cords)
{
	while (cords.j < vars->heigth)
	{
		cords.i = 0;
		cords.map_i = 0;
		if (vars->is_big)
		{
			cords.map_i = max_int(0, vars->hero_x - vars->vision / 2);
			if (vars->max_x - vars->vision > 0)
				cords.map_i = min_int(cords.map_i, vars->max_x - vars->vision);
		}
		while (cords.i < vars->width)
		{
			put_img(vars, cords);
			cords.map_i++;
			cords.i += FRAME;
		}
		cords.map_j++;
		cords.j += FRAME;
	}
}

void	render(t_vars *vars)
{
	t_cord	cords;

	cords.j = 0;
	cords.map_j = 0;
	if (vars->is_big)
	{
		cords.map_j = max_int(0, (vars->hero_y - (vars->vision / 2)));
		if (vars->max_y - vars->vision > 0)
		{
			cords.map_j = min_int(cords.map_j, vars->max_y - vars->vision);
		}
	}
	draw_map(vars, cords);
	ft_put_moves(vars);
}
