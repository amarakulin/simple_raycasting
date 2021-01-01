/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:43:51 by tilda             #+#    #+#             */
/*   Updated: 2020/10/30 21:20:07 by tilda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char const		*copy;
	char			*res;
	unsigned int	i;

	copy = s;
	i = 0;
	if (s == 0 || f == 0)
	{
		return (0);
	}
	if (!(res = (char *)malloc((ft_strlen(s) + 1) * sizeof(char))))
	{
		return (0);
	}
	while (copy[i] != '\0')
	{
		res[i] = f(i, copy[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}
