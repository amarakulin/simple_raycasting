
#include "libft.h"

int	ft_tolower(int symbol)
{
	if (symbol >= 65 && symbol <= 90)
	{
		symbol += 32;
	}
	return (symbol);
}
