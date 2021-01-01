/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 23:16:58 by tilda             #+#    #+#             */
/*   Updated: 2020/10/30 15:41:20 by tilda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char *temp;

	temp = s;
	while (n != 0)
	{
		if (*temp == c)
		{
			return ((char *)temp);
		}
		temp++;
		n--;
	}
	temp = 0;
	return ((char *)temp);
}
