/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:08:44 by ftassada          #+#    #+#             */
/*   Updated: 2021/12/25 00:01:01 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	destroy_images(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->sprites.adm);
	mlx_destroy_image(vars->mlx, vars->sprites.wall);
	mlx_destroy_image(vars->mlx, vars->sprites.floor);
	mlx_destroy_image(vars->mlx, vars->sprites.hero);
	mlx_destroy_image(vars->mlx, vars->sprites.pnsh);
}

void	free_all(t_vars *vars)
{
	destroy_images(vars);
	free_map(&(vars->map), vars->max_y - 1, 0, 0);
	mlx_destroy_window(vars->mlx, vars->win);
	ft_putstr_fd("Thanks for playing my game :D\n", 1);
}

int	check_format(char *file)
{
	size_t	i;

	i = ft_strlen(file);
	if (file[i - 1] == 'r' && file[i - 2] == 'e' && file[i - 3] == 'b' \
		&& file[i - 4] == '.')
		return (1);
	return (0);
}

void	free_map(char ***map, int cur_y, int errflag, int fd)
{
	int	i;

	i = 0;
	while (cur_y >= 0)
	{
		free((*map)[cur_y--]);
	}
	if (errflag == 1)
		put_error(fd);
}

void	put_error(int fd)
{
	if (fd != 0)
		close(fd);
	ft_putstr_fd("Error\n", 1);
	exit(1);
}
