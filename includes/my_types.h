/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:36:41 by ftassada          #+#    #+#             */
/*   Updated: 2021/11/09 22:10:48 by ftassada         ###   ########.fr       */
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
	EXIT		= 'E'
};

typedef struct s_img	t_img;
typedef struct s_vars	t_vars;
typedef struct s_spr	t_spr;
typedef struct s_val	t_val;

struct s_spr
{
	void	*main_hero;
	void	*bocal;
	void	*wall;
	void	*floor;
	void	*punish;
	void	*tij;
};

struct s_img
{
	void	*image;
	char	*adr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

struct s_vars
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_spr	sprites;
	int		x;
	int		y;
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

t_vars	init_vars(void);

#endif
