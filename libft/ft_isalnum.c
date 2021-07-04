
#include "libft.h"

int	ft_isalnum(int symbol)
{
	if (symbol >= 48 && symbol <= 57)
	{
		return (1);
	}
	if (symbol >= 65 && symbol <= 90)
	{
		return (1);
	}
	if (symbol >= 97 && symbol <= 122)
	{
		return (1);
	}
	return (0);
}
