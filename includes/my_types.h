/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:36:41 by ftassada          #+#    #+#             */
/*   Updated: 2022/01/10 22:03:38 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_TYPES_H
# define MY_TYPES_H

typedef enum e_props	t_props;

enum e_props
{
	FLOOR		= '0',
	WALL		= '1',
	PLAYER		= 'P',
	COLLECTIBLE = 'C',
	EXIT		= 'E',
};

typedef struct s_img	t_img;
typedef struct s_vars	t_vars;
typedef struct s_spr	t_spr;
typedef struct s_val	t_val;
typedef struct s_cord	t_cord;

struct s_spr
{
	void	*hero;
	void	*adm;
	void	*wall;
	void	*floor;
	void	*pnsh;
};

struct s_cord
{
	int	i;
	int	j;
	int	map_i;
	int	map_j;
};

struct s_vars
{
	void	*mlx;
	void	*win;
	t_spr	sprites;
	int		hero_x;
	int		hero_y;
	int		collected;
	int		max_col;
	int		max_x;
	int		max_y;
	int		moves;
	int		is_big;
	int		width;
	int		heigth;
	int		vision;
	char	**map;
};

struct s_val
{
	int	wall;
	int	floor;
	int	col;
	int	player;
	int	exit;
	int	symbols;
};

void	init_vars(t_vars *vars);

#endif
