/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 21:09:37 by ftassada          #+#    #+#             */
/*   Updated: 2021/12/25 01:33:08 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# define PROJECT_NAME "SoLoooong :)"

# include "mlx.h"
# include "mlx_buttons.h"
# include "my_types.h"
# include "get_next_line.h"
# include "images.h"
# include "parser.h"
# include "libft.h"
#include <stdio.h>

void	put_error(int fd);
void	free_map(char ***map, int cur_y, int errflag, int fd);
void	render(t_vars *vars);
void	render_big(t_vars *vars);
void	pl_move(t_vars *vars, int x, int y);
void	free_all(t_vars *vars);
#endif
