/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_casting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 15:52:41 by tilda             #+#    #+#             */
/*   Updated: 2020/12/18 15:52:43 by tilda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_vars(int x, t_w_cas *vars, t_data *data)
{
	vars->camera_y = 2 * x / (double)data->param.w - 1;
	vars->ray_dir_y = data->hero.dir_y + data->hero.plane_y * vars->camera_y;
	vars->ray_dir_x = data->hero.dir_x + data->hero.plane_x * vars->camera_y;
	vars->map_y = (int)data->hero.y;
	vars->map_x = (int)data->hero.x;
	vars->delta_dist_y = sqrt(1 + pow(vars->ray_dir_x, 2) /
								pow(vars->ray_dir_y, 2));
	vars->delta_dist_x = sqrt(1 + pow(vars->ray_dir_y, 2) /
								pow(vars->ray_dir_x, 2));
}

void	set_side_dist_and_step(t_w_cas *vars, t_data *data)
{
	vars->step_x = 1;
	vars->step_y = 1;
	if (vars->ray_dir_x < 0)
	{
		vars->step_x = -1;
		vars->side_dist_x = (data->hero.x - vars->map_x) * vars->delta_dist_x;
	}
	else
	{
		vars->side_dist_x = (1.0 + vars->map_x - data->hero.x) *
											vars->delta_dist_x;
	}
	if (vars->ray_dir_y < 0)
	{
		vars->step_y = -1;
		vars->side_dist_y = (data->hero.y - vars->map_y) * vars->delta_dist_y;
	}
	else
	{
		vars->side_dist_y = (1.0 + vars->map_y - data->hero.y) *
											vars->delta_dist_y;
	}
}

void	get_data_when_ray_hit_walls(t_w_cas *vars, t_data *data)
{
	int hit;

	hit = 0;
	while (hit != 1)
	{
		if (vars->side_dist_x < vars->side_dist_y)
		{
			vars->side_dist_x += vars->delta_dist_x;
			vars->map_x += vars->step_x;
			vars->side = 0;
		}
		else
		{
			vars->side_dist_y += vars->delta_dist_y;
			vars->map_y += vars->step_y;
			vars->side = 1;
		}
		if (data->map.map[vars->map_y][vars->map_x] == '1')
			hit = 1;
	}
}

void	get_start_end_walls(t_w_cas *vars, t_data *data)
{
	int		neg_ray_dir_x;
	int		neg_ray_dir_y;

	neg_ray_dir_x = (1 - vars->step_x) / 2;
	neg_ray_dir_y = (1 - vars->step_y) / 2;
	if (vars->side == 0)
	{
		vars->perp_wall_dist = (vars->map_x - data->hero.x + neg_ray_dir_x) /
				vars->ray_dir_x;
	}
	else
	{
		vars->perp_wall_dist = (vars->map_y - data->hero.y + neg_ray_dir_y) /
				vars->ray_dir_y;
	}
	vars->line_h = (int)(data->param.h / vars->perp_wall_dist);
	vars->draw_start_wall = -vars->line_h / 2 + data->param.h / 2;
	vars->draw_end_wall = vars->line_h / 2 + data->param.h / 2;
	if (vars->draw_start_wall < 0)
		vars->draw_start_wall = 0;
	if (vars->draw_end_wall >= data->param.h)
		vars->draw_end_wall = data->param.h - 1;
}

/*
** data->wall_cast.z_buff[x] allow to see sprites
*/

void	wall_casting(t_data *data)
{
	int			x;
	t_w_cas		vars;

	vars = data->wall_cast;
	x = 0;
	while (x < data->param.w)
	{
		init_vars(x, &vars, data);
		set_side_dist_and_step(&vars, data);
		get_data_when_ray_hit_walls(&vars, data);
		get_start_end_walls(&vars, data);
		texture_calculation(x, &vars, data);
		data->wall_cast.z_buff[x] = vars.perp_wall_dist;
		x++;
	}
}
