/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_logic_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 22:35:06 by ftassada          #+#    #+#             */
/*   Updated: 2022/01/11 00:43:44 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

static void	enemy_move(t_vars *vars, t_enemy *enemy, int x, int y)
{
	vars->map[enemy->y + y][enemy->x + x] = ENEMY;
	vars->map[enemy->y][enemy->x] = FLOOR;
	enemy->x += x;
	enemy->y += y;
}

void	enemies_move(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->cur_enemies)
	{
		if (vars->map[vars->enemies[i].y][vars->enemies[i].x + 1] == FLOOR)
			enemy_move(vars, &(vars->enemies[i]), 1, 0);
		else if (vars->map[vars->enemies[i].y][vars->enemies[i].x - 1] == FLOOR)
			enemy_move(vars, &(vars->enemies[i]), -1, 0);
		else if (vars->map[vars->enemies[i].y + 1][vars->enemies[i].x] == FLOOR)
			enemy_move(vars, &(vars->enemies[i]), 0, 1);
		else if (vars->map[vars->enemies[i].y - 1][vars->enemies[i].x] == FLOOR)
			enemy_move(vars, &(vars->enemies[i]), 0, -1);
		i++;
	}
}
