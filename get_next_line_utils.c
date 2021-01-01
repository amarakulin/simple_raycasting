/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 21:53:29 by tilda             #+#    #+#             */
/*   Updated: 2020/11/16 23:29:01 by tilda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	str_len;

	i = 0;
	if (!(s))
		return (0);
	str_len = ft_strlen(s);
	if ((size_t)start >= str_len)
		return ("");
	if (str_len - (size_t)start < len)
		len = str_len - (size_t)start;
	if (!(res = (char *)malloc((len + 1) * sizeof(char))) || (!s))
		return (0);
	while (i < len && s[start])
	{
		res[i++] = s[start++];
	}
	res[i] = 0;
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*cont_str;
	size_t	i;
	size_t	j;

	if (!(s1) || !(s2))
		return (0);
	i = 0;
	j = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(cont_str = (char *)malloc(total_len * sizeof(char))))
		return (0);
	while (s1[i])
		cont_str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		cont_str[j++] = s2[i++];
	cont_str[j] = 0;
	return (cont_str);
}

char	*ft_strdup(const char *s1)
{
	char		*buff;
	const char	*copy;
	size_t		len;
	size_t		i;

	copy = s1;
	i = 0;
	len = ft_strlen(copy) + 1;
	if (!(buff = (char *)malloc(len * sizeof(char))))
		return (0);
	while (copy[i] != '\0')
	{
		buff[i] = copy[i];
		i++;
	}
	buff[i] = '\0';
	return ((char *)buff);
}

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
