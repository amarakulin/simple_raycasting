
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char *first_match_char;

	first_match_char = 0;
	while (*s)
	{
		if (*s == c)
		{
			first_match_char = s;
			return ((char *)first_match_char);
		}
		s++;
	}
	if (*s == c)
	{
		first_match_char = s;
		return ((char *)first_match_char);
	}
	return ((char *)first_match_char);
}
