/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:30:14 by tilda             #+#    #+#             */
/*   Updated: 2020/11/03 19:10:12 by tilda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t			count_src;
	long	int		i;
	long	int		dstsize_copy;

	i = 0;
	if (!(src) && !(dst))
		return (0);
	dstsize_copy = dstsize;
	if (!(count_src = ft_strlen(src)))
	{
		dst[i] = '\0';
		return (0);
	}
	while (dstsize_copy - 1 > i)
	{
		if (src[i] == '\0')
			break ;
		dst[i] = src[i];
		i++;
	}
	if (i != 0)
		dst[i] = '\0';
	return (count_src);
}
