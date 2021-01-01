/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:48:23 by tilda             #+#    #+#             */
/*   Updated: 2020/12/21 15:48:25 by tilda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			fast_mlx_pixel_put(size_t x, size_t y, t_data *data,
									unsigned int color)
{
	char	*dest;

	dest = data->win.addr + (y * data->win.l_len + x * (data->win.bit_pp / 8));
	*(unsigned int*)dest = color;
}

unsigned int	get_color_pixel(int x, int y, t_texture texture)
{
	char	*dest;

	dest = texture.addr + (y * texture.l_len + x * (texture.bit_pp / 8));
	return (*(unsigned int*)dest);
}

void			print_map_on_window(t_data *data)
{
	wall_casting(data);
	sprite_casting(data);
	mlx_put_image_to_window(data->win.mlx, data->win.win, data->win.img, 0, 0);
}
