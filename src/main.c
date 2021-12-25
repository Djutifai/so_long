/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 21:12:27 by ftassada          #+#    #+#             */
/*   Updated: 2021/12/24 22:05:54 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2 || !check_format(argv[1]))
		put_error(0);
	vars = parse_this(argv[1]);
	mlx_loop(vars.mlx);
	return (1);
}
