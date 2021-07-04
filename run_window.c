
#include "cub3d.h"

int		buttons(int keycode, t_data *data)
{
	data->hero.speed = 0.2;
	data->hero.rotate = M_PI / 30;
	mlx_destroy_image(data->win.mlx, data->win.img);
	data->win.img = mlx_new_image(data->win.mlx, data->param.w, data->param.h);
	data->win.addr = mlx_get_data_addr(data->win.img,
					&data->win.bit_pp, &data->win.l_len, &data->win.en);
	if (keycode == 53)
		close_win(data);
	else if (keycode == 13 || keycode == 1)
		move_up_down(keycode, data);
	else if (keycode == 2 || keycode == 0)
		move_left_right(keycode, data);
	else if (keycode == 123)
		rotate_right(data);
	else if (keycode == 124)
		rotate_left(data);
	print_map_on_window(data);
	return (1);
}

void	run_window(t_data *data)
{
	mlx_hook(data->win.win, 2, 1L << 0, buttons, data);
	mlx_hook(data->win.win, 17, 0, close_win, data);
	mlx_loop(data->win.mlx);
}
