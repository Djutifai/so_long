/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 21:09:33 by ftassada          #+#    #+#             */
/*   Updated: 2021/11/03 19:26:11 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	render(t_vars *vars)
{
	void	*img_main_hero;
	int		i[2];

	img_main_hero = mlx_xpm_file_to_image(vars->mlx, "sprites/myMan.xpm", &i[0], &i[1]);
	vars->img.image = img_main_hero;
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.image, vars->x, vars->y);
	return (1);
}

static int	press_key(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEY)
		exit(1);
	if (vars->x >= 0 && vars->x <= WIDTH && vars->y >= 0 && vars->y <= HEIGTH)
	{
		if (keycode == W_KEY)
			vars->y -= 3;
		else if (keycode == A_KEY)
			vars->x -= 3;
		else if (keycode == S_KEY)
			vars->y += 3;
		else if (keycode == D_KEY)
			vars->x += 3;
	}
	return (0);
}

t_vars	init_vars(void)
{
	t_vars	vars;
	char	*path_to_my_man;
	int		img_width;
	int		img_heigth;

	ft_putstr("Hello and welcome\n");
	path_to_my_man = "sprites/myMan.xpm";
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGTH, PROJECT_NAME);
	vars.x = 200;
	vars.y = 200;
	vars.sprites.main_hero = mlx_xpm_file_to_image(vars.mlx, path_to_my_man, &img_width, &img_heigth);
	mlx_hook(vars.win, KEY_PRESS, KEY_PRESS_MASK, press_key, &vars);
	mlx_loop_hook(vars.mlx, render, &vars);
	return (vars);
}
