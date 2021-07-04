
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *term;

	term = b;
	while (len != 0)
	{
		*term = c;
		len--;
		term++;
	}
	return (b);
}
