
#include <printf.h>
#include "get_next_line.h"

int		return_line(char **str_stat, char **line)
{
	char		*tmp;

	if ((tmp = ft_strchr(*str_stat, '\n')))
	{
		if (!(*line = ft_substr(*str_stat, 0, tmp - *str_stat)))
			return (-1);
		if (!(tmp = ft_strdup(tmp + 1)))
			return (-1);
		free(*str_stat);
		if (!(*str_stat = ft_strdup(tmp)))
			return (-1);
		free(tmp);
		return (1);
	}
	return (2);
}

int		read_or_ending(int fd, char **str_stat, char **line)
{
	char		*buff;
	char		*joined_str;
	ssize_t		bsize;

	if (!(buff = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char))))
		return (-1);
	if ((bsize = read(fd, buff, BUFFER_SIZE)) == -1)
		return (-1);
	buff[bsize] = 0;
	if (bsize == 0 && !(ft_strchr(*str_stat, '\n')))
	{
		if (!(*line = ft_strdup(*str_stat)))
			return (-1);
		free(buff);
		return (0);
	}
	joined_str = ft_strjoin(*str_stat, buff);
	free(*str_stat);
	free(buff);
	if (!(*str_stat = ft_strdup(joined_str)))
		return (-1);
	free(joined_str);
	return (2);
}

int		get_next_line(int fd, char **line)
{
	static char		*str_stat = NULL;
	int				state;

	if (BUFFER_SIZE <= 0 || fd < 0 || !line)
		return (-1);
	if (!str_stat)
		str_stat = ft_strdup("");
	while (1)
	{
		state = return_line(&str_stat, line);
		if (state != 2)
			return (state);
		state = read_or_ending(fd, &str_stat, line);
		if (state != 2)
		{
			free(str_stat);
			str_stat = 0;
			return (state);
		}
	}
	return (1);
}
