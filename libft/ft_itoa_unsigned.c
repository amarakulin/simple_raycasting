/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 00:23:32 by tilda             #+#    #+#             */
/*   Updated: 2020/11/23 00:23:36 by tilda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*to_str(unsigned int n, unsigned int len)
{
	char	*str;
	char	*arr;

	arr = "0123456789";
	if (!(str = (char *)malloc((len + 1) * sizeof(char))))
		return (0);
	str[len] = 0;
	while (len != 0)
	{
		len--;
		str[len] = arr[(n % 10)];
		n /= 10;
	}
	return (str);
}

char			*ft_itoa_unsigned(unsigned int n)
{
	char				*str;
	unsigned int		copy_n;
	unsigned int		len;

	len = 0;
	if (n == 0)
		len = 1;
	copy_n = n;
	while (copy_n != 0)
	{
		copy_n /= 10;
		len++;
	}
	str = to_str(n, len);
	return (str);
}
