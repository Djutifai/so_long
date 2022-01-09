/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_math_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftassada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:31:31 by ftassada          #+#    #+#             */
/*   Updated: 2022/01/09 21:34:39 by ftassada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

int	min_int(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	max_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
