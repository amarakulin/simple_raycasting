
#include "cub3d.h"

void	move_up_down(int keycode, t_data *data)
{
	if (keycode == 13)
	{
		if (data->map.map[(int)(data->hero.y + data->hero.dir_y *
			(data->hero.speed * 1.5))][(int)(data->hero.x)] != '1')
			data->hero.y += data->hero.dir_y * data->hero.speed;
		if (data->map.map[(int)(data->hero.y)][(int)(data->hero.x +
			data->hero.dir_x * (data->hero.speed * 1.5))] != '1')
			data->hero.x += data->hero.dir_x * data->hero.speed;
	}
	else if (keycode == 1)
	{
		if (data->map.map[(int)(data->hero.y - data->hero.dir_y *
			(data->hero.speed * 1.5))][(int)(data->hero.x)] != '1')
			data->hero.y -= data->hero.dir_y * data->hero.speed;
		if (data->map.map[(int)(data->hero.y)][(int)(data->hero.x -
			data->hero.dir_x * (data->hero.speed * 1.5))] != '1')
			data->hero.x -= data->hero.dir_x * data->hero.speed;
	}
}

void	move_left_right(int keycode, t_data *data)
{
	if (keycode == 2)
	{
		if (data->map.map[(int)(data->hero.y + data->hero.plane_y *
			(data->hero.speed * 1.5))][(int)(data->hero.x)] != '1')
			data->hero.y += data->hero.plane_y * data->hero.speed;
		if (data->map.map[(int)(data->hero.y)][(int)(data->hero.x +
			data->hero.plane_x * (data->hero.speed * 1.5))] != '1')
			data->hero.x += data->hero.plane_x * data->hero.speed;
	}
	else if (keycode == 0)
	{
		if (data->map.map[(int)(data->hero.y - data->hero.plane_y *
			(data->hero.speed * 1.5))][(int)(data->hero.x)] != '1')
			data->hero.y -= data->hero.plane_y * data->hero.speed;
		if (data->map.map[(int)(data->hero.y)][(int)(data->hero.x -
			data->hero.plane_x * (data->hero.speed * 1.5))] != '1')
			data->hero.x -= data->hero.plane_x * data->hero.speed;
	}
}

void	rotate_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->hero.dir_x;
	data->hero.dir_x = data->hero.dir_x * cos(data->hero.rotate) -
						data->hero.dir_y * sin(data->hero.rotate);
	data->hero.dir_y = old_dir_x * sin(data->hero.rotate) +
				data->hero.dir_y * cos(data->hero.rotate);
	old_plane_x = data->hero.plane_x;
	data->hero.plane_x = data->hero.plane_x * cos(data->hero.rotate) -
							data->hero.plane_y * sin(data->hero.rotate);
	data->hero.plane_y = old_plane_x * sin(data->hero.rotate) +
						data->hero.plane_y * cos(data->hero.rotate);
}

void	rotate_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->hero.dir_x;
	data->hero.dir_x = data->hero.dir_x * cos(-data->hero.rotate) -
					data->hero.dir_y * sin(-data->hero.rotate);
	data->hero.dir_y = old_dir_x * sin(-data->hero.rotate) +
					data->hero.dir_y * cos(-data->hero.rotate);
	old_plane_x = data->hero.plane_x;
	data->hero.plane_x = data->hero.plane_x * cos(-data->hero.rotate) -
						data->hero.plane_y * sin(-data->hero.rotate);
	data->hero.plane_y = old_plane_x * sin(-data->hero.rotate) +
						data->hero.plane_y * cos(-data->hero.rotate);
}

int		close_win(t_data *data)
{
	ft_putendl_fd("[+] ESC: Close the window", 1);
	mlx_destroy_image(data->win.mlx, data->win.img);
	mlx_clear_window(data->win.mlx, data->win.win);
	mlx_destroy_window(data->win.mlx, data->win.win);
	exit(0);
}
