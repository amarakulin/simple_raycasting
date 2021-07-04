
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	str_len;

	i = 0;
	if (!(s))
		return (0);
	str_len = ft_strlen(s);
	if ((size_t)start >= str_len)
		return (ft_strdup(""));
	if (str_len - (size_t)start < len)
		len = str_len - (size_t)start;
	if (!(res = (char *)malloc((len + 1) * sizeof(char))) || (!s))
		return (0);
	while (i < len && s[start])
	{
		res[i++] = s[start++];
	}
	res[i] = 0;
	return (res);
}
