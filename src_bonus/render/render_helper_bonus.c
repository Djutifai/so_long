/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_helper_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:03:30 by ftassada          #+#    #+#             */
/*   Updated: 2022/01/10 21:48:18 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_bonus.h"

char	*ft_put_moves(t_vars *vars)
{
	char	*move;
	char	*res;
	char	*moves_str;

	moves_str = ft_strdup("Moves: ");
	move = ft_itoa(vars->moves);
	res = ft_strjoin(moves_str, move);
	mlx_string_put(vars->mlx, vars->win, 0, 15, \
		255 << 16 | 255 << 8 | 0, res);
	ft_putstr_fd(res, 1);
	write(1, "\n", 1);
	free(res);
	free(move);
	return (res);
}

void	put_img(t_vars *vars, t_cord cords)
{
	void	*img;

	if (vars->map[cords.map_j][cords.map_i] == WALL)
		img = vars->sprites.wall;
	else if (vars->map[cords.map_j][cords.map_i] == PLAYER)
		img = vars->sprites.hero;
	else if (vars->map[cords.map_j][cords.map_i] == COLLECTIBLE)
		img = vars->sprites.pnsh;
	else if (vars->map[cords.map_j][cords.map_i] == EXIT)
		img = vars->sprites.adm;
	else if (vars->map[cords.map_j][cords.map_i] == ENEMY)
		img = vars->sprites.tij;
	else
		img = vars->sprites.floor;
	if (vars->map[cords.map_j][cords.map_i] == 'P' || \
		vars->map[cords.map_j][cords.map_i] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, \
			vars->sprites.floor, cords.i, cords.j);
	mlx_put_image_to_window(vars->mlx, vars->win, img, cords.i, cords.j);
}
