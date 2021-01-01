/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:55:37 by tilda             #+#    #+#             */
/*   Updated: 2020/11/03 19:55:52 by tilda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	{
		cont_str[j++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		cont_str[j++] = s2[i++];
	}
	cont_str[j] = 0;
	return (cont_str);
}
