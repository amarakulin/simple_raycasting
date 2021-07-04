
#include "libft.h"

static	char	*to_str(size_t n, size_t len)
{
	char	*str;
	char	*arr;

	arr = "0123456789abcdef";
	if (!(str = (char *)malloc((len + 1) * sizeof(char))))
		return (0);
	str[len] = 0;
	while (len != 0)
	{
		len--;
		str[len] = arr[(n % 16)];
		n /= 16;
	}
	return (str);
}

char			*ft_itoa_hex(size_t n)
{
	char	*str;
	size_t	copy_n;
	size_t	len;

	len = 0;
	if (n == 0)
		len = 1;
	copy_n = n;
	while (copy_n != 0)
	{
		copy_n /= 16;
		len++;
	}
	str = to_str(n, len);
	return (str);
}
