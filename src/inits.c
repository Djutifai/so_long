/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 21:09:33 by ftassada          #+#    #+#             */
/*   Updated: 2021/12/25 01:56:52 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static int	press_key(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEY)
		exit(1);
	if (keycode == W_KEY || keycode == A_KEY || keycode == S_KEY \
		|| keycode == D_KEY)
	{
		if (vars->hero_x >= 0 && vars->hero_x <= vars->width && \
			vars->hero_y >= 0 && vars->hero_y <= vars->heigth)
		{
			mlx_clear_window(vars->mlx, vars->win);
			if (keycode == W_KEY && vars->hero_y - 1 >= 0)
				pl_move(vars, 0, -1);
			else if (keycode == A_KEY && vars->hero_x - 1 >= 0)
				pl_move(vars, -1, 0);
			else if (keycode == S_KEY && vars->hero_y + 1 <= vars->max_y)
				pl_move(vars, 0, 1);
			else if (keycode == D_KEY && vars->hero_x + 1 <= vars->max_x)
				pl_move(vars, 1, 0);
			if (vars->is_big)
				render_big(vars);
			else
				render(vars);
				printf("HEY\n");
		}
	}
	return (0);
}

static void	init_sprites(t_vars *vars)
{
	char	*path;
	int		img_w;
	int		img_h;

	path = "sprites/myMan.xpm";
	vars->sprites.hero = mlx_xpm_file_to_image(vars->mlx, path, &img_w, &img_h);
	if (vars->sprites.hero == NULL)
		printf("ERRORhero\n");
	path = "sprites/col.xpm";
	vars->sprites.pnsh = mlx_xpm_file_to_image(vars->mlx, path, &img_w, &img_h);
	if (vars->sprites.pnsh == NULL)
		printf("pnsh\n");
	path = "sprites/wall.xpm";
	vars->sprites.wall = mlx_xpm_file_to_image(vars->mlx, path, &img_w, &img_h);
	if (vars->sprites.wall == NULL)
		printf("ERROR wall\n");
	path = "sprites/exit.xpm";
	vars->sprites.adm = mlx_xpm_file_to_image(vars->mlx, path, &img_w, &img_h);
	if (vars->sprites.adm == NULL)
		printf("ERROR adm\n");
	path = "sprites/floor.xpm";
	vars->sprites.floor = mlx_xpm_file_to_image(vars->mlx, \
		path, &img_w, &img_h);
	if (vars->sprites.floor == NULL)
		printf("ERROR floor!\n");
}

void	init_vars(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (vars->max_x * 25 <= 800 && vars->max_y * 25 <= 800)
	{
		vars->win = mlx_new_window(vars->mlx, vars->max_x * 25, \
			vars->max_y * 25, PROJECT_NAME);
		vars->width = vars->max_x * 25;
		vars->heigth = vars->max_y * 25;
		vars->is_big = 0;
	}
	else
	{
		vars->win = mlx_new_window(vars->mlx, 800, 800, PROJECT_NAME);
		vars->width = 800;
		vars->heigth = 800;
		vars->is_big = 1;
	}
	vars->moves = 0;
	vars->collected = 0;
	init_sprites(vars);
	mlx_hook(vars->win, KEY_PRESS, KEY_PRESS_MASK, press_key, vars);
}
