/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_colored_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smia <smia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 01:05:29 by smia              #+#    #+#             */
/*   Updated: 2022/02/08 08:25:22 by smia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	has_comma(char *str)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (str[i] && r == 0)
	{
		if (str[i] == ',')
			r = 1;
		i++;
	}
	return (r);
}

void	handle_colored_map(t_fstack *f_stack, char **nsp, int j, int i)
{
	f_stack->matrix[j][i].z = ft_atoi(nsp[0]);
	f_stack->matrix[j][i].color = hex_to_dec(nsp[1]);
	free(nsp[0]);
	free(nsp[1]);
	free(nsp);
}

void	init_color(t_fstack *f_stack, int i, int j)
{
	if (f_stack->matrix[j][i].z == 0)
		f_stack->matrix[j][i].color = 0xffffff;
	else if (f_stack->matrix[j][i].z > 0)
		f_stack->matrix[j][i].color = 0x00FF00;
	else if (f_stack->matrix[j][i].z < 0)
		f_stack->matrix[j][i].color = 0xFF0000;
}
