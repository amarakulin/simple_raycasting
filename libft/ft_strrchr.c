
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *last_match_char;

	last_match_char = 0;
	while (*s)
	{
		if (*s == c)
		{
			last_match_char = s;
		}
		s++;
	}
	if (c == '\0')
	{
		last_match_char = s;
		return ((char *)last_match_char);
	}
	return ((char *)last_match_char);
}
