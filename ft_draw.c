/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smia <smia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:52:25 by smia              #+#    #+#             */
/*   Updated: 2022/02/08 07:56:50 by smia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	scale_coords(t_cmatrix *a, t_cmatrix *b, t_fstack *f_stack)
{
	isometric(&(a->x), &(a->y), a->z);
	isometric(&(b->x), &(b->y), b->z);
	a->x = a->x * f_stack->zoom;
	a->y = a->y * f_stack->zoom;
	b->x = b->x * f_stack->zoom;
	b->y = b->y * f_stack->zoom;
	a->x += f_stack->win_w / 2;
	a->y += f_stack->win_h / 2;
	b->x += f_stack->win_w / 2;
	b->y += f_stack->win_h / 2;
}

static void	bresenham(t_cmatrix a, t_cmatrix b, t_fstack *f_stack)
{
	float	dx;
	float	dy;
	float	max;
	int		color;

	color = f_stack->matrix[(int)a.y][(int)a.x].color;
	scale_coords(&a, &b, f_stack);
	dx = b.x - a.x;
	dy = b.y - a.y;
	max = get_max(get_mod(dx), get_mod(dy));
	dx /= max;
	dy /= max;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		if (a.x > f_stack->win_w || a.y > f_stack->win_h || a.y < 0 || a.x < 0)
			break ;
		mlx_pixel_put(f_stack->mlx, f_stack->mlx_win, a.x, a.y, a.color);
		a.x += dx;
		a.y += dy;
	}
}

void	draw_matrix(t_fstack *f_stack)
{
	int	x;
	int	y;

	y = 0;
	while (f_stack->matrix[y])
	{
		x = 0;
		while (1)
		{
			if (f_stack->matrix[y + 1])
				bresenham(f_stack->matrix[y][x], f_stack->matrix[y + 1][x] \
						, f_stack);
			if (!f_stack->matrix[y][x].is_last)
				bresenham(f_stack->matrix[y][x], f_stack->matrix[y][x + 1] \
						, f_stack);
			if (f_stack->matrix[y][x].is_last)
				break ;
			x++;
		}
		y++;
	}
}
