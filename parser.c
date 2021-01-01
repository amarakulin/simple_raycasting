/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 16:19:16 by tilda             #+#    #+#             */
/*   Updated: 2020/12/04 16:19:17 by tilda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parsing(int argc, char **argv, t_data **data)
{
	int		fd;

	fd = 0;
	if (!(argc == 2 || argc == 3))
		print_out_errors(2);
	if (!(*data = ft_calloc(1, sizeof(t_data))))
		print_out_errors(10);
	if (!validate_arg(argv[1]))
		print_out_errors(4);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		print_out_errors(5);
	if (!(read_file(fd, *data)))
		print_out_errors(10);
	close(fd);
	if (!(validate_param(*data)))
		print_out_errors(3);
	if (!(validate_map(*data)))
		print_out_errors(6);
	ft_putendl_fd("[+] Valid Parameters and Map", 1);
	if (!(init_data(*data)))
		print_out_errors(10);
	if (argc == 3 && !(validate_save_arg(argv[2])))
		print_out_errors(7);
}
