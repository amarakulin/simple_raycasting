
#include "libft.h"

int	ft_toupper(int symbol)
{
	if (symbol >= 97 && symbol <= 122)
	{
		symbol -= 32;
	}
	return (symbol);
}
