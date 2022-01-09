/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 21:12:27 by ftassada          #+#    #+#             */
/*   Updated: 2022/01/09 21:34:39 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2 || !check_format(argv[1]))
		put_error(0);
	vars = parse_this(argv[1]);
	mlx_loop(vars.mlx);
	return (1);
}
