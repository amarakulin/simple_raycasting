
#include "libft.h"

static	char	*to_str(char *str, long n, int flag_minus, int len)
{
	str[len] = 0;
	while ((len != 0 && flag_minus == 1) || (len != 1 && flag_minus == -1))
	{
		len--;
		str[len] = (n % 10) * flag_minus + '0';
		n /= 10;
	}
	if (flag_minus == -1)
	{
		len--;
		str[len] = '-';
	}
	return (str);
}

char			*ft_itoa(long n)
{
	char	*str;
	long	copy_n;
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
	}
	copy_n = n;
	while (copy_n != 0)
	{
		copy_n /= 10;
		len++;
	}
	if (!(str = (char *)malloc((len + 1) * sizeof(char))))
		return (0);
	str = to_str(str, n, flag_minus, len);
	return (str);
}
