/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 13:42:28 by tilda             #+#    #+#             */
/*   Updated: 2020/12/19 13:42:30 by tilda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_texture(int i, t_data *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (data->textr[i].w != x)
	{
		y = 0;
		while (data->textr[i].h != y)
		{
			data->textr[i].arr_textr[data->textr[i].w * y + x] =
					(int)get_color_pixel(x, y, data->textr[i]);
			y++;
		}
		x++;
	}
}

int		load_img(t_data *data)
{
	int		i;
	int		error;

	i = 0;
	error = 1;
	while (i != 5)
	{
		data->textr[i].img = mlx_xpm_file_to_image(data->win.mlx,
				data->param.paths[i], &data->textr[i].w, &data->textr[i].h);
		data->textr[i].addr = mlx_get_data_addr(data->textr[i].img,
		&data->textr[i].bit_pp, &data->textr[i].l_len, &data->textr[i].en);
		if (!(data->textr[i].arr_textr =
		(int *)malloc(sizeof(int) * data->textr[i].w * data->textr[i].h)))
			print_out_errors(10);
		fill_texture(i, data);
		i++;
	}
	return (error);
}
