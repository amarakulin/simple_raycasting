/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 22:58:55 by tilda             #+#    #+#             */
/*   Updated: 2020/11/02 17:08:21 by tilda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*copy_dst;
	const char	*copy_src;
	char		*back_dst;
	const char	*back_src;

	copy_dst = dst;
	copy_src = src;
	if (copy_dst < copy_src)
	{
		while (len--)
			*copy_dst++ = *copy_src++;
	}
	else if (copy_dst == copy_src)
		return (dst);
	else
	{
		back_dst = copy_dst + (len - 1);
		back_src = copy_src + (len - 1);
		while (len--)
			*back_dst-- = *back_src--;
	}
	return (dst);
}
