
#include "cub3d.h"

int		validate_border_symbols(size_t x, size_t y, t_data *data)
{
	int valid;

	valid = 1;
	if (y == 0 || x == 0
		|| y == data->map.h_map - 1
		|| x == data->map.len_map - 1)
	{
		if (!(data->map.map[y][x] == '1' || data->map.map[y][x] == ' '))
			valid = 0;
	}
	return (valid);
}

/*
** Checks symbols up, down, right, left in the map
** Should be only '1' and/or ' '
*/

int		check_space(size_t x, size_t y, t_data *data)
{
	int		valid;

	valid = 1;
	if (y != 0 &&
		!(data->map.map[y - 1][x] == '1' ||
		data->map.map[y - 1][x] == ' '))
		valid = 0;
	if (y != data->map.h_map - 1 &&
		!(data->map.map[y + 1][x] == '1' ||
		data->map.map[y + 1][x] == ' '))
		valid = 0;
	if (x != data->map.len_map - 1 &&
		!(data->map.map[y][x + 1] == '1' ||
		data->map.map[y][x + 1] == ' '))
		valid = 0;
	if (x != 0 &&
		!(data->map.map[y][x - 1] == '1' ||
		data->map.map[y][x - 1] == ' '))
		valid = 0;
	return (valid);
}

int		validate_inner_symbols(size_t x, size_t y, t_data *data)
{
	int		valid;

	valid = 1;
	if (data->map.map[y][x] == ' ')
	{
		if (!(check_space(x, y, data)))
			valid = 0;
	}
	else if (!(ft_strchr("012NSEW", data->map.map[y][x])))
		valid = 0;
	return (valid);
}

int		validate_line(size_t y, size_t *hero, t_data *data)
{
	size_t	x;
	int		valid;

	x = 0;
	valid = 1;
	while (valid == 1 && data->map.map[y][x])
	{
		if (!(validate_border_symbols(x, y, data)))
			valid = 0;
		if (ft_strchr("NSEW", data->map.map[y][x]))
			(*hero)++;
		else if (data->map.map[y][x] == '2')
			data->map.nbr_sp++;
		if (!(validate_inner_symbols(x, y, data)))
			valid = 0;
		x++;
	}
	return (valid);
}

int		validate_map(t_data *data)
{
	size_t	y;
	size_t	hero;
	int		valid;

	y = 0;
	valid = 1;
	hero = 0;
	while (valid == 1 && data->map.h_map != y)
	{
		valid = validate_line(y, &hero, data);
		y++;
	}
	if (hero != 1 || data->map.nl >= 1)
		valid = 0;
	return (valid);
}
