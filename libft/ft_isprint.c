
#include "libft.h"

int	ft_isprint(int symbol)
{
	if (symbol >= 32 && symbol <= 126)
	{
		return (1);
	}
	return (0);
}
