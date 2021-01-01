/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 23:20:43 by tilda             #+#    #+#             */
/*   Updated: 2020/11/22 23:20:45 by tilda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*to_str(int n, int flag_minus, int len, unsigned int base)
{
	char	*str;
	char	*arr;

	arr = "0123456789abcdef";
	if (!(str = (char *)malloc((len + 1) * sizeof(char))))
		return (0);
	str[len] = 0;
	while ((len != 0 && flag_minus == 1) || (len != 1 && flag_minus == -1))
	{
		len--;
		str[len] = arr[(n % base)];
		n /= base;
	}
	if (flag_minus == -1)
	{
		len--;
		str[len] = '-';
	}
	return (str);
}

char			*ft_itoa_base(int n, unsigned int base)
{
	char	*str;
	int		copy_n;
	int		flag_minus;
	int		len;

	flag_minus = 1;
	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
	{
		flag_minus = -1;
		len++;
		n *= -1;
	}
	copy_n = n;
	while (copy_n != 0)
	{
		copy_n /= base;
		len++;
	}
	str = to_str(n, flag_minus, len, base);
	return (str);
}
