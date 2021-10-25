/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 22:00:53 by ftassada          #+#    #+#             */
/*   Updated: 2021/10/25 22:22:14 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

enum e_props
{
	WALL	= 0,
	COLLECTIBLE,
	FLOOR
};

typedef struct s_img	t_img;
typedef struct s_vars	t_vars;

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
};

t_vars	init_vars(void);

#endif STRUCTS_H