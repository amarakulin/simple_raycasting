
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char *temp;

	temp = s;
	while (n != 0)
	{
		if (*temp == c)
		{
			return ((char *)temp);
		}
		temp++;
		n--;
	}
	temp = 0;
	return ((char *)temp);
}
