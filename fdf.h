/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smia <smia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 07:17:19 by smia              #+#    #+#             */
/*   Updated: 2022/02/08 08:25:39 by smia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx_macos/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include <unistd.h>
# include <math.h>
# define BUFFER_SIZE 100

typedef struct c_matrix
{
	float	x;
	float	y;
	float	z;
	int		color;
	int		is_last;
}t_cmatrix;

typedef struct f_stack
{
	int			height;
	int			width;
	t_cmatrix	**matrix;
	int			zoom;
	void		*mlx;
	void		*mlx_win;
	int			win_w;
	int			win_h;
	int			bpp;
	float		z_scale;
	int			line_length;
	int			color;
}	t_fstack;

char		*ft_strjoin(char const *s1, char const *s2);
char		*get_next_line(int fd);
size_t		ft_strlen(char const *str);
char		**ft_split(char const *s, char c);
int			ft_atoi(char const *s);
void		draw_matrix(t_fstack *f_stack);
float		get_mod(float i);
float		get_max(float a, float b);
void		isometric(float *x, float *y, float z);
int			init_matrix(int fd, char *file, t_fstack *f_stack);
int			has_comma(char *str);
int			hex_to_dec(char *str);
int			get_map_width(const char *str, char c);
int			check_line_width(const char *str);
void		handle_colored_map(t_fstack *f_stack, char **nsp, int j, int i);
void		init_color(t_fstack *f_stack, int i, int j);

#endif