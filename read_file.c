/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 16:25:14 by tilda             #+#    #+#             */
/*   Updated: 2020/12/26 16:25:16 by tilda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Add in the end of str the spaces
** spaces = the diff between longest str(len_map) and current str
*/

char	*addback_space_to_str(char *str, t_data *data)
{
	char	*spaces;
	char	*result_str;
	size_t	len;

	len = ft_strlen(str);
	if (len < data->map.len_map)
	{
		if (!(spaces = ft_calloc((data->map.len_map - len) + 1, sizeof(char))))
			print_out_errors(10);
		ft_memset(spaces, ' ', data->map.len_map - len);
		if (!(result_str = ft_strjoin(str, spaces)))
			print_out_errors(10);
		free(spaces);
	}
	else
	{
		if (!(result_str = ft_strdup(str)))
			print_out_errors(10);
	}
	return (result_str);
}

int		convert_lst_to_arr(t_list *head, t_data *data)
{
	size_t		lst_size;
	size_t		i;
	char		*str;

	lst_size = ft_lstsize(head);
	data->map.h_map = lst_size;
	if (!(data->map.map = ft_calloc((data->map.h_map + 1), sizeof(char *))))
		print_out_errors(10);
	i = 0;
	while (head)
	{
		if (head->content)
		{
			str = addback_space_to_str((char *)head->content, data);
			data->map.map[i++] = str;
		}
		head = head->next;
	}
	return (1);
}

char	*check_arg(char *line)
{
	char *copy_line;

	if (!(copy_line = ft_strtrim(line, " ")))
		print_out_errors(10);
	if (!(ft_strchr("RNSWEFC\n", *copy_line)))
	{
		free(copy_line);
		copy_line = 0;
	}
	return (copy_line);
}

char	*create_lst_param(int fd, t_data *data)
{
	char	*line;
	char	*tmp;
	t_list	*param;
	int		ret;

	ret = 1;
	line = NULL;
	tmp = NULL;
	if (!(param = ft_lstnew(line)))
		print_out_errors(10);
	while ((ret = get_next_line(fd, &line)))
	{
		if (*line)
		{
			if (!(tmp = check_arg(line)))
				break ;
			ft_lstadd_front(&param, ft_lstnew(tmp));
		}
		free(line);
	}
	if (ret == -1)
		print_out_errors(10);
	data->param.lst_param = param;
	return (line);
}

/*
** Initialize map to the structure data
*/

int		read_file(int fd, t_data *data)
{
	char	*line;
	t_list	*head;
	size_t	len_line;
	int		ret;

	data->map.nl = 0;
	data->map.len_map = 0;
	line = create_lst_param(fd, data);
	if (!(head = ft_lstnew(line)))
		print_out_errors(10);
	while ((ret = get_next_line(fd, &line)))
	{
		len_line = ft_strlen(line);
		if (len_line > data->map.len_map)
			data->map.len_map = len_line;
		if (!(*line))
			data->map.nl++;
		ft_lstadd_back(&head, ft_lstnew(line));
	}
	if (ret == -1)
		print_out_errors(10);
	ft_lstadd_back(&head, ft_lstnew(line));
	convert_lst_to_arr(head, data);
	ft_lstclear(&head, &del);
	return (1);
}
