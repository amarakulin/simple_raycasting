
#include "libft.h"

int	ft_atoi(const char *str)
{
	long long int	res;
	int				flag_minus;

	flag_minus = 1;
	res = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32) || (*str == 48))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			flag_minus = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (res * 10 < res)
			return ((res * flag_minus > 0) ? -1 : 0);
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (int)(res * flag_minus);
}
