/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 21:09:33 by ftassada          #+#    #+#             */
/*   Updated: 2021/10/25 22:22:31 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solong.h"
#include "structs.h"

t_vars	init_vars(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(&vars.mlx, WIDTH, HEIGTH, PROJECT_NAME);
	vars.img.image = mlx_new_image(&vars.mlx, WIDTH, HEIGTH);
	vars.img.adr = mlx_get_data_addr(vars.img.image, &vars.img.bits_per_pixel, \
		&vars.img.line_length, &vars.img.endian);
	return (vars);
}
