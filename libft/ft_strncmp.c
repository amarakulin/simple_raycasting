
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_c;
	unsigned char	*s2_c;

	i = 0;
	s1_c = (unsigned char *)s1;
	s2_c = (unsigned char *)s2;
	if (n != 0)
	{
		while (n - 1 != 0 && (s1_c[i] && s2_c[i]))
		{
			if (s1_c[i] != s2_c[i])
			{
				return (s1_c[i] - s2_c[i]);
			}
			i++;
			n--;
		}
	}
	else
		return (0);
	return (s1_c[i] - s2_c[i]);
}
