/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 21:17:49 by tilda             #+#    #+#             */
/*   Updated: 2020/11/10 20:32:08 by tilda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	clean_double_arr(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str[i]);
	free(str);
}

static	size_t	count_split_part(const	char *s, char c)
{
	size_t			count;
	size_t			i;
	char			flag;

	flag = 'f';
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && flag == 'f')
		{
			count++;
			flag = 't';
		}
		if (s[i] == c && flag == 't')
			flag = 'f';
		i++;
	}
	return (count);
}

static	char	*create_new_str(const char *s, char c, char **main_str)
{
	size_t			len_new_str;
	const	char	*s_copy;

	len_new_str = 0;
	s_copy = s;
	while (*s_copy != c && *s_copy != 0)
	{
		len_new_str++;
		s_copy++;
	}
	if (!(*main_str = ft_substr(s, 0, len_new_str)))
		return (0);
	s = s_copy;
	return ((char *)s);
}

char			**ft_split(char const *s, char c)
{
	char			**main_str;
	char			**res;
	size_t			total_len;

	if (!(s))
		return (0);
	total_len = count_split_part(s, c);
	if (!(main_str = (char **)ft_calloc((total_len + 1), sizeof(char *))))
		return (0);
	res = main_str;
	while (*s)
	{
		if (*s == c)
			s++;
		if (*s != 0 && *s != c)
		{
			if (!(s = create_new_str(s, c, main_str++)))
			{
				clean_double_arr(res);
				return (0);
			}
		}
	}
	return (res);
}
