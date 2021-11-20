/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 21:12:27 by ftassada          #+#    #+#             */
/*   Updated: 2021/11/08 21:23:59 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	main(int argc, char **argv)
{
	if (argc != 2 || !check_format(argv[1]))
		put_error(0);
	parse_this(argv[1]);
	//vars = init_vars();
	//mlx_loop(vars.mlx);
	return (1);
}
