/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 21:09:33 by ftassada          #+#    #+#             */
/*   Updated: 2022/01/11 01:32:21 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static int	exit_window(int key, t_vars *vars)
{
	(void)key;
	(void)vars;
	ft_putstr_fd("Thanks for playing my game! :D\n", 1);
	exit(0);
	return (1);
}

static int	press_key(int key, t_vars *vars)
{
	if (key == ESC_KEY)
	{
		free_all(vars, 0);
		exit(0);
	}
	if (key == W_KEY || key == A_KEY || key == S_KEY || key == D_KEY)
	{
		if (vars->hero_x >= 0 && vars->hero_x <= vars->width && \
			vars->hero_y >= 0 && vars->hero_y <= vars->heigth)
		{
			mlx_clear_window(vars->mlx, vars->win);
			if (key == W_KEY && vars->hero_y - 1 >= 0)
				pl_move(vars, 0, -1);
			else if (key == A_KEY && vars->hero_x - 1 >= 0)
				pl_move(vars, -1, 0);
			else if (key == S_KEY && vars->hero_y + 1 <= vars->max_y)
				pl_move(vars, 0, 1);
			else if (key == D_KEY && vars->hero_x + 1 <= vars->max_x)
				pl_move(vars, 1, 0);
			render(vars);
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
	path = "sprites/col.xpm";
	vars->sprites.pnsh = mlx_xpm_file_to_image(vars->mlx, path, &img_w, &img_h);
	path = "sprites/wall.xpm";
	vars->sprites.wall = mlx_xpm_file_to_image(vars->mlx, path, &img_w, &img_h);
	path = "sprites/exit.xpm";
	vars->sprites.adm = mlx_xpm_file_to_image(vars->mlx, path, &img_w, &img_h);
	path = "sprites/floor.xpm";
	vars->sprites.floor = mlx_xpm_file_to_image(vars->mlx, \
		path, &img_w, &img_h);
}

static void	help_to_init(t_vars *vars)
{
	if (vars->max_x * FRAME <= MAX_WIDTH && vars->max_y * FRAME <= MAX_HEGTH)
	{
		vars->win = mlx_new_window(vars->mlx, vars->max_x * FRAME, \
			vars->max_y * FRAME, PROJECT_NAME);
		vars->width = vars->max_x * FRAME;
		vars->heigth = vars->max_y * FRAME;
		vars->vision = 0;
		vars->is_big = 0;
	}
	else
	{
		vars->width = min_int(MAX_WIDTH, vars->max_x * FRAME);
		vars->heigth = min_int(MAX_HEGTH, vars->max_y * FRAME);
		vars->win = mlx_new_window(vars->mlx, vars->width, vars->heigth, \
			PROJECT_NAME);
		vars->vision = MAX_WIDTH / FRAME;
		vars->is_big = 1;
		vars->vision = 24;
	}
}

void	init_vars(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		free_all(vars, 1);
	vars->moves = 0;
	vars->collected = 0;
	help_to_init(vars);
	init_sprites(vars);
	mlx_hook(vars->win, KEY_PRESS, KEY_PRESS_MASK, press_key, vars);
	mlx_hook(vars->win, CLOSE_WIN, CLOSE_WIN_MASK, exit_window, 0);
}
