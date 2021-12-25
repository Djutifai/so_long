/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:03:30 by ftassada          #+#    #+#             */
/*   Updated: 2021/12/25 19:07:46 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

char	*ft_put_moves(t_vars *vars)
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

void	put_img(t_vars *vars, int i, int j)
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