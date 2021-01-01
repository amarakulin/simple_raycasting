/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_calculation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:33:05 by tilda             #+#    #+#             */
/*   Updated: 2020/12/31 19:08:57 by tilda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		get_data_texture(t_texture *texture, t_w_cas *vars, t_data *data)
{
	if (vars->side == 0)
		vars->wall_x = data->hero.y + vars->perp_wall_dist * vars->ray_dir_y;
	else
		vars->wall_x = data->hero.x + vars->perp_wall_dist * vars->ray_dir_x;
	vars->wall_x -= floor(vars->wall_x);
	texture->tex_x = (int)(vars->wall_x * (double)texture->w);
	if (vars->side == 0)
		texture->tex_x = texture->w - texture->tex_x - 1;
	if (vars->side == 1)
		texture->tex_x = texture->w - texture->tex_x - 1;
	texture->step = 1.0 * texture->h / vars->line_h;
	texture->tex_pos = (vars->draw_start_wall - data->param.h / 2 +
						vars->line_h / 2)
			* texture->step;
}

t_texture	choose_textr(t_w_cas *vars, t_data *data)
{
	t_texture	texture;

	if (vars->side == 1 && data->hero.y > vars->map_y)
		texture = (data->textr)[1];
	else if (vars->side == 1 && data->hero.y < vars->map_y)
		texture = (data->textr)[2];
	else if (vars->side == 0 && data->hero.x > vars->map_x)
		texture = (data->textr)[3];
	else if (vars->side == 0 && data->hero.x < vars->map_x)
		texture = (data->textr)[4];
	else
		texture = (data->textr)[0];
	return (texture);
}

void		texture_calculation(int x, t_w_cas *vars, t_data *data)
{
	int			y;
	int			tex_y;
	size_t		color;
	t_texture	texture;

	y = 0;
	tex_y = 0;
	color = 0;
	texture = choose_textr(vars, data);
	get_data_texture(&texture, vars, data);
	while (y < data->param.h)
	{
		if (y >= vars->draw_start_wall && y <= vars->draw_end_wall)
		{
			tex_y = (int)texture.tex_pos & (texture.h - 1);
			texture.tex_pos += texture.step;
			color = texture.arr_textr[texture.h * tex_y + texture.tex_x];
			fast_mlx_pixel_put(x, y, data, color);
		}
		else if (y < vars->draw_start_wall)
			fast_mlx_pixel_put(x, y, data, data->param.color_ceiling);
		else
			fast_mlx_pixel_put(x, y, data, data->param.color_floor);
		y++;
	}
}
