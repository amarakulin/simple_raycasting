
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;

	i = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (dstsize == 0)
	{
		dst[len_dst] = '\0';
		return (len_src);
	}
	if (len_dst + 1 > dstsize)
		return (dstsize + len_src);
	while (dstsize > len_dst + i + 1 && src[i] != '\0')
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = 0;
	return (len_src + len_dst);
}
