/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 23:04:38 by tilda             #+#    #+#             */
/*   Updated: 2020/11/09 11:45:20 by tilda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t		len_s2;

	len_s2 = ft_strlen(s2);
	if (len_s2 == 0)
		return ((char *)s1);
	while (len != 0)
	{
		if (ft_strlen(s1) < len_s2)
			return (0);
		else
		{
			if (ft_strncmp(s1, s2, len_s2) == 0 && len >= len_s2)
			{
				return ((char *)s1);
			}
		}
		s1++;
		len--;
	}
	return (0);
}
