
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *first;
	unsigned char *second;

	if (n <= 0)
		return (0);
	first = (unsigned char *)s1;
	second = (unsigned char *)s2;
	while ((n != 0) && (first != '\0') && (second != '\0'))
	{
		if (*first != *second)
		{
			if (*second == 0)
				return (*first - *second);
			else
				return (*first - *second);
		}
		n--;
		if (n != 0)
		{
			first++;
			second++;
		}
	}
	return (*first - *second);
}
