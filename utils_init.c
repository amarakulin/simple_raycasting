/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 19:59:59 by tilda             #+#    #+#             */
/*   Updated: 2020/12/29 20:00:00 by tilda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	create_trgb(int r, int g, int b)
{
	return (0 << 24 | r << 16 | g << 8 | b);
}

void			init_hero_n_s(size_t x, size_t y, t_data *data)
{
	data->hero.x = (double)x + 0.5;
	data->hero.y = (double)y + 0.5;
	if (data->map.map[y][x] == 'N')
	{
		data->hero.dir_y = -1;
		data->hero.dir_x = 0;
		data->hero.plane_x = 0.66;
		data->hero.plane_y = 0;
	}
	else if (data->map.map[y][x] == 'S')
	{
		data->hero.dir_y = 1;
		data->hero.dir_x = 0;
		data->hero.plane_x = -0.66;
		data->hero.plane_y = 0;
	}
}

void			init_hero_w_e(size_t x, size_t y, t_data *data)
{
	if (data->map.map[y][x] == 'W')
	{
		data->hero.dir_y = 0;
		data->hero.dir_x = -1;
		data->hero.plane_x = 0;
		data->hero.plane_y = -0.66;
	}
	else if (data->map.map[y][x] == 'E')
	{
		data->hero.dir_y = 0;
		data->hero.dir_x = 1;
		data->hero.plane_x = 0;
		data->hero.plane_y = 0.66;
	}
}

void			init_floor_celling(char *str, char param, t_data *data)
{
	int	red;
	int	green;
	int	blue;

	str = skip_spaces(str, 2);
	red = ft_atoi(str);
	str += count_len_int(red, str);
	while (*str == ' ' || *str == ',')
		str++;
	green = ft_atoi(str);
	str += count_len_int(green, str);
	while (*str == ' ' || *str == ',')
		str++;
	blue = ft_atoi(str);
	if (param == 'F')
		data->param.color_floor = create_trgb(red, green, blue);
	else if (param == 'C')
		data->param.color_ceiling = create_trgb(red, green, blue);
}

/*
** paths[0] - Sprite
** paths[1] - N
** paths[2] - S
** paths[3] - E
** paths[4] - W
*/

void			init_path(char *str, char param, t_data *data)
{
	if (param == 'B')
		str = skip_spaces(str, 2);
	else
		str = skip_spaces(str, 3);
	if (param == 'B')
		data->param.paths[0] = str;
	else if (param == 'N')
		data->param.paths[1] = str;
	else if (param == 'S')
		data->param.paths[2] = str;
	else if (param == 'W')
		data->param.paths[3] = str;
	else if (param == 'E')
		data->param.paths[4] = str;
}
