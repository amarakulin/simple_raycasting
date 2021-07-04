
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*buff;
	const char	*copy;
	size_t		len;
	size_t		i;

	if (!s1)
		return (0);
	copy = s1;
	i = 0;
	len = ft_strlen(copy) + 1;
	if (!(buff = (char *)malloc(len * sizeof(char))))
	{
		return (0);
	}
	while (copy[i] != '\0')
	{
		buff[i] = copy[i];
		i++;
	}
	buff[i] = '\0';
	return ((char *)buff);
}
