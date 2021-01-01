/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 13:10:47 by tilda             #+#    #+#             */
/*   Updated: 2020/12/05 13:10:49 by tilda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char *argv[])
{
	t_data	*data;

	parsing(argc, argv, &data);
	ft_putendl_fd("[+] Window is open", 1);
	print_map_on_window(data);
	if (argc == 3)
		create_screenshot(data);
	run_window(data);
	return (0);
}
