
#include "cub3d.h"

/*
** 14 is number of bytes in file_header
** 40 is number of bytes in info_header
*/

void	write_file_header(int fd, int trgb, t_data *data)
{
	unsigned char	file_header[14];
	int				file_size;

	ft_bzero(file_header, 14);
	file_size = 40 + 14 + trgb * data->param.h * data->param.w;
	file_header[0] = (unsigned char)('B');
	file_header[1] = (unsigned char)('M');
	file_header[2] = (unsigned char)(file_size);
	file_header[3] = (unsigned char)(file_size >> 8);
	file_header[4] = (unsigned char)(file_size >> 16);
	file_header[5] = (unsigned char)(file_size >> 24);
	file_header[10] = (unsigned char)(14 + 40);
	write(fd, file_header, 14);
}

/*
** 40 is number of bytes in info_header
*/

void	write_info_header(int fd, int trgb, t_data *data)
{
	unsigned char	info_header[40];

	ft_bzero(info_header, 40);
	info_header[0] = (unsigned char)(40);
	info_header[4] = (unsigned char)(data->param.w);
	info_header[5] = (unsigned char)(data->param.w >> 8);
	info_header[6] = (unsigned char)(data->param.w >> 16);
	info_header[7] = (unsigned char)(data->param.w >> 24);
	info_header[8] = (unsigned char)(data->param.h);
	info_header[9] = (unsigned char)(data->param.h >> 8);
	info_header[10] = (unsigned char)(data->param.h >> 16);
	info_header[11] = (unsigned char)(data->param.h >> 24);
	info_header[12] = (unsigned char)(1);
	info_header[14] = (unsigned char)(trgb * 8);
	write(fd, info_header, 40);
}

/*
** trgb number of bytes: truncate, red, green, blue
** len number of bytes in one l_len in the data->win.addr
*/

int		create_screenshot(t_data *data)
{
	int		fd;
	int		trgb;
	int		i;
	int		len;

	len = data->param.w * (data->win.bit_pp / 8);
	i = data->param.h - 1;
	trgb = 4;
	if (!(fd = open("screenshot.bmp", O_CREAT | O_TRUNC | O_RDWR, 0644)))
		return (0);
	write_file_header(fd, trgb, data);
	write_info_header(fd, trgb, data);
	while (i != -1)
	{
		write(fd, data->win.addr + i * data->win.l_len, len);
		i--;
	}
	close(fd);
	ft_putendl_fd("[+] Screenshot has been created", 1);
	exit(0);
}

int		validate_save_arg(char *save_arg)
{
	int		valid;
	size_t	len;

	valid = 1;
	len = ft_strlen(save_arg);
	if (len != 6)
		valid = 0;
	if (ft_strncmp(save_arg, "--save", 6) != 0)
		valid = 0;
	return (valid);
}
