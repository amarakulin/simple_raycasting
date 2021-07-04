
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *s;

	if (!(s = (void *)malloc(count * size)))
		return (0);
	ft_memset(s, 0, count * size);
	return (s);
}
