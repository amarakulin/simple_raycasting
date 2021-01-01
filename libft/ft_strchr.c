/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:04:25 by tilda             #+#    #+#             */
/*   Updated: 2020/11/09 11:36:50 by tilda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char *first_match_char;

	first_match_char = 0;
	while (*s)
	{
		if (*s == c)
		{
			first_match_char = s;
			return ((char *)first_match_char);
		}
		s++;
	}
	if (*s == c)
	{
		first_match_char = s;
		return ((char *)first_match_char);
	}
	return ((char *)first_match_char);
}
