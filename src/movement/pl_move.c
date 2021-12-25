/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 23:53:07 by ftassada          #+#    #+#             */
/*   Updated: 2021/12/25 01:33:14 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	win(t_vars *vars)
{
	ft_putstr_fd("Congratulations, you have won!\n", 1);
	free_all(vars);
	exit(0);
}

void	pl_move(t_vars *vars, int x, int y)
{
	char	c;

	c = vars->map[vars->hero_y + y][vars->hero_x + x];
	if (c == WALL)
		return ;
	else if (c == EXIT)
	{
		if (vars->collected == vars->max_col)
			win(vars);
		return ;
	}
	else if (c == COLLECTIBLE)
	{
		vars->collected += 1;
	}
	vars->map[vars->hero_y + y][vars->hero_x + x] = PLAYER;
	vars->map[vars->hero_y][vars->hero_x] = FLOOR;
	vars->hero_x += x;
	vars->hero_y += y;
	vars->moves += 1;
}
