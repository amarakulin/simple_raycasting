
#include "cub3d.h"


/*
** Set the coordinates of each sprite
** Set the coordinates for hero
*/
void			read_map(t_data *data)
{
	size_t		x;
	size_t		y;
	int			i;

	y = -1;
	i = 0;
	while (data->map.map[++y])
	{
		x = -1;
		while (data->map.map[y][++x])
		{
			if (data->map.map[y][x] == '2' && data->map.nbr_sp != 0)
			{
				data->sprite[i].x = (double)x + 0.45;
				data->sprite[i].y = (double)y + 0.45;
				i++;
			}
			else if (data->map.map[y][x] != '1' && data->map.map[y][x] != '0'
												&& data->map.map[y][x] != ' ')
			{
				init_hero_n_s(x, y, data);
				init_hero_w_e(x, y, data);
			}
		}
	}
}

void			init_resolution(char *str, t_data *data)
{
	int		height;
	int		width;

	str = skip_spaces(str, 2);
	width = ft_atoi(str);
	str += count_len_int(width, str);
	while (*str == ' ')
		str++;
	height = ft_atoi(str);
	mlx_get_screen_size(data->win.mlx, &data->param.w, &data->param.h);
	if (width < data->param.w)
		data->param.w = width;
	if (height < data->param.h)
		data->param.h = height;
}

void			choose_param_init(char *str, t_data *data)
{
	if (ft_strncmp(str, "R ", 2) == 0)
		init_resolution(str, data);
	else if (ft_strncmp(str, "NO ", 3) == 0)
		init_path(str, 'N', data);
	else if (ft_strncmp(str, "SO ", 3) == 0)
		init_path(str, 'S', data);
	else if (ft_strncmp(str, "WE ", 3) == 0)
		init_path(str, 'W', data);
	else if (ft_strncmp(str, "EA ", 3) == 0)
		init_path(str, 'E', data);
	else if (ft_strncmp(str, "S ", 2) == 0)
		init_path(str, 'B', data);
	else if (ft_strncmp(str, "F ", 2) == 0)
		init_floor_celling(str, 'F', data);
	else if (ft_strncmp(str, "C ", 2) == 0)
		init_floor_celling(str, 'C', data);
	else
		ft_putendl_fd("Fail", 1);
}

void			set_params(t_data *data)
{
	t_list	*lst;
	char	*tmp_str;

	lst = data->param.lst_param;
	while (lst->next)
	{
		tmp_str = lst->content;
		if (*(tmp_str))
			choose_param_init(tmp_str, data);
		lst = lst->next;
	}
}

int				init_data(t_data *data)
{
	int		error;

	error = 1;
	if (data->map.nbr_sp != 0)
	{
		if (!(data->sprite = ft_calloc(sizeof(t_sprite), data->map.nbr_sp)))
			print_out_errors(10);
	}
	if (!(data->textr = (t_texture *)ft_calloc(sizeof(t_texture), 5)))
		print_out_errors(10);
	set_params(data);
	read_map(data);
	data->win.mlx = mlx_init();
	data->win.win = mlx_new_window(data->win.mlx, data->param.w,
									data->param.h, "cub3D");
	data->win.img = mlx_new_image(data->win.mlx, data->param.w, data->param.h);
	data->win.addr = mlx_get_data_addr(data->win.img,
						&data->win.bit_pp, &data->win.l_len, &data->win.en);
	load_img(data);
	if (!(data->wall_cast.z_buff = ft_calloc(sizeof(double), data->param.w)))
		print_out_errors(10);
	return (error);
}
