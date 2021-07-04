
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char *temp;

	temp = s;
	while (n != 0)
	{
		*temp = '\0';
		n--;
		temp++;
	}
}
