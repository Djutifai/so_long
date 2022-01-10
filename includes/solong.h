/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 21:09:37 by ftassada          #+#    #+#             */
/*   Updated: 2022/01/11 00:46:08 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# define PROJECT_NAME	"SoLoooong :)"
# define FRAME 			25
# define MAX_WIDTH		600
# define MAX_HEGTH		600
# define MAX_VISION		5;

# include "mlx.h"
# include "mlx_buttons.h"
# include "my_types.h"
# include "get_next_line.h"
# include "images.h"
# include "parser.h"
# include "libft.h"

void	put_error(int fd);
void	free_all(t_vars *vars, int errflag);
void	free_map(char ***map, int cur_y, int errflag, int fd);
void	pl_move(t_vars *vars, int x, int y);
void	render(t_vars *vars);
int		min_int(int a, int b);
int		max_int(int a, int b);

#endif
