/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smia <smia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 01:08:54 by smia              #+#    #+#             */
/*   Updated: 2022/02/08 01:43:08 by smia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_map_width(const char *str, char c)
{
	int	width;
	int	i;

	i = 0;
	width = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i])
			width++;
		while (str[i] != c && str[i])
			i++;
	}
	return (width);
}

int	check_line_width(const char *str)
{
	int		i;
	int		width;
	char	**sp;

	i = 0;
	width = 0;
	sp = ft_split(str, ' ');
	while (sp[i])
	{
		if (ft_atoi(sp[i]) != 0 || sp[i][0] == '0')
			width++;
		free(sp[i]);
		i++;
	}
	free(sp);
	return (width);
}
