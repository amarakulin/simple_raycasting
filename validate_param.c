
#include "cub3d.h"

int		check_path(char *str, size_t index)
{
	int	valid;
	int	fd;

	valid = 1;
	str = skip_spaces(str, index);
	fd = open(str, O_RDONLY);
	if (fd < 0)
		valid = 0;
	close(fd);
	return (valid);
}

int		check_resolution(char *str, size_t index)
{
	int		valid;
	int		total_nbr;

	total_nbr = 0;
	valid = 1;
	str = skip_spaces(str, index);
	while (*str && valid == 1 && total_nbr <= 2)
	{
		if (*str == '0')
			valid = 0;
		if (*str >= '0' && *str <= '9' && *str)
		{
			total_nbr += 1;
			while (*str >= '0' && *str <= '9' && *str)
				str++;
		}
		while (*str == ' ' && *str)
			str++;
		if (*str != 0 && !(*str >= '0' && *str <= '9' && *str))
			valid = 0;
	}
	if (total_nbr != 2)
		valid = 0;
	return (valid);
}

int		check_floor_celling(char *s, size_t index)
{
	int		n;
	int		total_nbr;
	int		comma;

	comma = 0;
	total_nbr = 0;
	s = index + s;
	while (*s)
	{
		n = 0;
		while (*s == ' ' && *s)
			s++;
		while (*s >= '0' && *s <= '9' && *s)
		{
			s += count_len_int(n = ft_atoi(s), s);
			total_nbr += 1;
		}
		if (*s == ',' && *s++)
			comma++;
		if ((*s != 0 && !(ft_strchr("0123456789 ", *s))) || n >= 256 || n < 0)
			return (0);
	}
	if (total_nbr != 3 || comma != 2)
		return (0);
	return (1);
}

int		choose_param_validate(char *str)
{
	int valid;

	valid = 1;
	if (ft_strncmp(str, "R ", 2) == 0)
		valid = check_resolution(str, 2);
	else if (ft_strncmp(str, "NO ", 3) == 0)
		valid = check_path(str, 3);
	else if (ft_strncmp(str, "SO ", 3) == 0)
		valid = check_path(str, 3);
	else if (ft_strncmp(str, "WE ", 3) == 0)
		valid = check_path(str, 3);
	else if (ft_strncmp(str, "EA ", 3) == 0)
		valid = check_path(str, 3);
	else if (ft_strncmp(str, "S ", 2) == 0)
		valid = check_path(str, 2);
	else if (ft_strncmp(str, "F ", 2) == 0 || ft_strncmp(str, "C ", 2) == 0)
		valid = check_floor_celling(str, 2);
	else
		valid = 0;
	return (valid);
}

int		validate_param(t_data *data)
{
	t_param		param;
	t_list		*lst;
	char		*tmp_str;
	int			count_param;
	int			valid;

	valid = 1;
	count_param = 0;
	param = data->param;
	lst = param.lst_param;
	while (lst->next && valid == 1)
	{
		tmp_str = lst->content;
		if (*tmp_str)
		{
			count_param++;
			valid = choose_param_validate(tmp_str);
		}
		lst = lst->next;
	}
	if (count_param != 8)
		valid = 0;
	return (valid);
}
