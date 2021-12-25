/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 00:44:16 by ftassada          #+#    #+#             */
/*   Updated: 2021/12/24 23:54:28 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "fcntl.h"

t_vars	parse_this(char *file);
void	validate_map(int fd, int *max_x, int *max_y, t_val *val);
int		check_format(char *file);
int		check_if_square(int fd, int max_x, int max_y);

#endif
