/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_clean_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 18:55:38 by tilda             #+#    #+#             */
/*   Updated: 2020/12/29 18:55:39 by tilda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_out_errors(int error)
{
	ft_putstr_fd("Number error is -> ", 1);
	ft_putnbr_fd(error, 1);
	ft_putchar_fd('\n', 1);
	if (error != 3 && error != 6 && error != 7)
	{
		perror("Error");
		if (error == 2)
			ft_putendl_fd("[-] No required number of files", 1);
		else if (error == 4)
			ft_putendl_fd("[-] Doesn't match .cub at the end.", 1);
		else if (error == 5)
			ft_putendl_fd("[-] Can't read the file", 1);
		else if (error >= 10)
			ft_putendl_fd("[-] Malloc can't allocate memory", 1);
	}
	else
	{
		if (error == 3)
			ft_putendl_fd("[-] Error: Invalid Parameters", 1);
		else if (error == 6)
			ft_putendl_fd("[-] Error: Invalid Map", 1);
		else if (error == 7)
			ft_putendl_fd("[-] Error: Invalid arg for screenshot", 1);
	}
	exit(-1);
}

void	del(void *str)
{
	free(str);
	str = NULL;
}
