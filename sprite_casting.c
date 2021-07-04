
#include "cub3d.h"

void	get_dist_from_hero_to_sprites(t_data *data)
{
	size_t j;

	j = 0;
	while (j < data->map.nbr_sp)
	{
		data->sprite[j].dis = ((data->hero.x - data->sprite[j].x) *
								(data->hero.x - data->sprite[j].x) +
								(data->hero.y - data->sprite[j].y) *
								(data->hero.y - data->sprite[j].y));
		j++;
	}
	sort_decreasing_sprites(0, (int)data->map.nbr_sp - 1, data);
}


/*
** transform sprite with the inverse camera matrix
** [ plane_x   dir_x ] -1                                       [ dir_y      -dir_x ]
** [               ]  = 1/(plane_x * dir_y - dir_x * plane_y) * [                 ]
** [ plane_y   dir_y ]                                          [ -plane_y  plane_x ]
*/
void	get_data_for_sprite(int i, t_sp_cas *vars, t_data *data)
{
	vars->sp_x = data->sprite[i].x - data->hero.x;
	vars->sp_y = data->sprite[i].y - data->hero.y;
	vars->inv_det = 1 / (data->hero.plane_x * data->hero.dir_y -
						data->hero.plane_y * data->hero.dir_x);
	vars->transf_x = vars->inv_det * (data->hero.dir_y * vars->sp_x -
						data->hero.dir_x * vars->sp_y);
	vars->transf_y = vars->inv_det * (-data->hero.plane_y * vars->sp_x +
						data->hero.plane_x * vars->sp_y);
	vars->sp_screen_x = (int)((data->param.w / 2) *
						(1 + vars->transf_x / vars->transf_y));
	vars->sp_h = abs((int)(data->param.h / vars->transf_y));
	vars->draw_start_y = -vars->sp_h / 2 + data->param.h / 2;
	if (vars->draw_start_y < 0)
		vars->draw_start_y = 0;
	vars->draw_end_y = vars->sp_h / 2 + data->param.h / 2;
	if (vars->draw_end_y >= data->param.h)
		vars->draw_end_y = data->param.h - 1;
	vars->sp_w = abs((int)(data->param.w / vars->transf_y));
	vars->draw_start_x = -vars->sp_w / 2 + vars->sp_screen_x;
	if (vars->draw_start_x < 0)
		vars->draw_start_x = 0;
	vars->draw_end_x = vars->sp_w / 2 + vars->sp_screen_x;
	if (vars->draw_end_x >= data->param.w)
		vars->draw_end_x = data->param.w - 1;
}

void	print_sprite(t_texture textr, t_sp_cas vars, t_data *data)
{
	int			x;
	int			y;
	int			avoid_floats;
	size_t		color;

	x = vars.draw_start_x - 1;
	while (++x < vars.draw_end_x)
	{
		vars.tex_x = (int)(256 * (x - (-vars.sp_w / 2 + vars.sp_screen_x)) *
				textr.w / vars.sp_w) / 256;
		y = vars.draw_start_y - 1;
		if (vars.transf_y > 0 && x > 0 && x < data->param.w && vars.transf_y <
													data->wall_cast.z_buff[x])
		{
			while (++y < vars.draw_end_y)
			{
				avoid_floats = y * 256 - data->param.h * 128 + vars.sp_h * 128;
				vars.tex_y = ((avoid_floats * textr.h) / vars.sp_h) / 256;
				color = textr.arr_textr[textr.w * vars.tex_y + vars.tex_x];
				if (color != 0)
					fast_mlx_pixel_put(x, y, data, color);
			}
		}
	}
}

void	sprite_casting(t_data *data)
{
	int			i;
	t_sp_cas	vars;
	t_texture	texture;

	i = 0;
	texture = data->textr[0];
	vars = data->sprite_cast;
	get_dist_from_hero_to_sprites(data);
	while (i < (int)data->map.nbr_sp)
	{
		get_data_for_sprite(i, &vars, data);
		print_sprite(texture, vars, data);
		i++;
	}
}
