/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_decreasing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:44:37 by tilda             #+#    #+#             */
/*   Updated: 2020/12/21 15:44:40 by tilda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	swap_sprites(int i, int j, t_data *data)
{
	t_sprite tmp;

	tmp = data->sprite[i];
	data->sprite[i] = data->sprite[j];
	data->sprite[j] = tmp;
}

int		partition(int low, int high, t_data *data)
{
	int pivot;
	int i;
	int j;

	pivot = data->sprite[high].dis;
	i = low - 1;
	j = low;
	while (j <= high - 1)
	{
		if (data->sprite[j].dis >= pivot)
		{
			i++;
			swap_sprites(i, j, data);
		}
		j++;
	}
	swap_sprites(i + 1, high, data);
	return (i + 1);
}

void	sort_decreasing_sprites(int low, int high, t_data *data)
{
	int pi;

	if (low < high)
	{
		pi = partition(low, high, data);
		sort_decreasing_sprites(low, pi - 1, data);
		sort_decreasing_sprites(pi + 1, high, data);
	}
}
