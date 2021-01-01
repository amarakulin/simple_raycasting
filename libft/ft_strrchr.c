/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:37:53 by tilda             #+#    #+#             */
/*   Updated: 2020/11/09 11:36:03 by tilda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *last_match_char;

	last_match_char = 0;
	while (*s)
	{
		if (*s == c)
		{
			last_match_char = s;
		}
		s++;
	}
	if (c == '\0')
	{
		last_match_char = s;
		return ((char *)last_match_char);
	}
	return ((char *)last_match_char);
}
