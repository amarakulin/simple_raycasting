/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 16:46:12 by tilda             #+#    #+#             */
/*   Updated: 2020/12/29 16:46:14 by tilda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		validate_arg(char *str)
{
	int		valid;
	size_t	len;

	valid = 1;
	len = ft_strlen(str);
	if (len <= 4)
		valid = 0;
	else
	{
		str += len - 4;
		if (ft_strncmp(str, ".cub", 4) != 0)
			valid = 0;
	}
	return (valid);
}

int		count_len_int(int nbr, char *str)
{
	int		len;

	len = 0;
	if (nbr == 0)
		len = 1;
	else
	{
		while (*str == '0')
		{
			str++;
			len++;
		}
		while (nbr != 0)
		{
			nbr /= 10;
			len++;
		}
	}
	return (len);
}

char	*skip_spaces(char *str, size_t index)
{
	str = str + index;
	while (*str == ' ' && *str)
		str++;
	return (str);
}
