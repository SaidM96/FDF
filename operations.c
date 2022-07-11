/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smia <smia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 22:32:39 by smia              #+#    #+#             */
/*   Updated: 2022/02/08 01:42:49 by smia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	get_mod(float i)
{
	float	r;

	r = i;
	if (i < 0)
		r = -i;
	return (r);
}

float	get_max(float a, float b)
{
	float	r;

	r = a;
	if (b > a)
		r = b;
	return (r);
}

void	isometric(float *x, float *y, float z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}
