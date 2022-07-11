/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smia <smia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 07:24:15 by smia              #+#    #+#             */
/*   Updated: 2022/02/08 08:25:53 by smia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	init_height_width(int fd, t_fstack *f_stack)
{
	char	*line;
	int		lw;

	line = get_next_line(fd);
	f_stack->width = check_line_width(line);
	while (line)
	{
		lw = check_line_width(line);
		free(line);
		if (lw != f_stack->width)
			return (-1);
		line = get_next_line(fd);
		f_stack->height++;
	}
	free(line);
	f_stack->height++;
	close(fd);
	return (1);
}

static void	init_color_z(t_fstack *f_stack, int j, char **sp)
{
	char		**nsp;
	int			i;

	i = 0;
	while (sp[i] && sp[i][0] != '\n')
	{
		if (has_comma(sp[i]))
		{
			nsp = ft_split(sp[i], ',');
			handle_colored_map(f_stack, nsp, j, i);
		}
		else
		{
			f_stack->matrix[j][i].z = ft_atoi(sp[i]);
			init_color(f_stack, i, j);
		}
		f_stack->matrix[j][i].x = i;
		f_stack->matrix[j][i].y = j;
		f_stack->matrix[j][i].is_last = 0;
		free(sp[i++]);
	}
	free(sp[i]);
	f_stack->matrix[j][--i].is_last = 1;
}

static void	fill_matrix(t_fstack *f_stack, int fd)
{
	int		j;
	char	*line;
	char	**sp;

	line = get_next_line(fd);
	j = 0;
	while (line)
	{
		sp = ft_split(line, ' ');
		f_stack->matrix[j] = malloc(sizeof(t_cmatrix) * f_stack->width + 1);
		if (!f_stack->matrix[j])
			return ;
		init_color_z(f_stack, j, sp);
		free(line);
		free(sp);
		line = get_next_line(fd);
		j++;
	}
	free(line);
	close(fd);
	f_stack->matrix[j] = NULL;
}

static void	init_mlx(t_fstack *f_stack)
{
	f_stack->mlx = mlx_init();
	f_stack->win_w = 1080;
	f_stack->win_h = 1080;
	f_stack->zoom = 15;
	if (f_stack->width > 50)
		f_stack->zoom = 4;
	if (f_stack->width > 200)
		f_stack->zoom = 2;
	f_stack->mlx_win = mlx_new_window(f_stack->mlx, f_stack->win_w, \
	f_stack->win_h, "fdf");
}

int	init_matrix(int fd, char *file, t_fstack *f_stack)
{
	int		fd2;
	int		r;

	f_stack->width = 0;
	f_stack->height = 0;
	r = init_height_width(fd, f_stack);
	if (r < 0)
		return (r);
	fd2 = open(file, O_RDONLY);
	if (fd2 < 0)
		return (-1);
	f_stack->matrix = malloc(sizeof(t_cmatrix *) * f_stack->height + 1);
	if (!f_stack->matrix)
		return (-1);
	fill_matrix(f_stack, fd2);
	init_mlx(f_stack);
	return (r);
}
