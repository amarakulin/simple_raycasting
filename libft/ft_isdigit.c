
#include "libft.h"

int	ft_isdigit(int symbol)
{
	if (symbol >= 48 && symbol <= 57)
	{
		return (1);
	}
	return (0);
}
