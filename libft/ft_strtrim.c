/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:53:33 by tilda             #+#    #+#             */
/*   Updated: 2020/11/09 14:03:02 by tilda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t		end_str(char const *copy_s1, char const *set)
{
	size_t		reverse;
	size_t		end;

	end = 0;
	reverse = ft_strlen(copy_s1) - 1;
	while (ft_strrchr(set, copy_s1[reverse]) != 0)
	{
		end += 1;
		reverse--;
	}
	return (end);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	char		*res;
	char const	*copy_s1;
	size_t		start;
	size_t		end;
	size_t		len;

	if (!(s1))
		return (0);
	start = 0;
	copy_s1 = s1;
	while (ft_strchr(set, *copy_s1) != 0 && *copy_s1)
	{
		start += 1;
		copy_s1++;
	}
	if (*copy_s1 == '\0')
		return (ft_strdup(copy_s1));
	end = end_str(copy_s1, set);
	len = ft_strlen(s1);
	if (len <= start + end)
		len = 0;
	else
		len = len - (end + start);
	res = ft_substr(s1, start, len);
	return (res);
}
