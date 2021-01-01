/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 20:25:10 by tilda             #+#    #+#             */
/*   Updated: 2020/11/03 22:17:12 by tilda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list		*list;

	list = (t_list*)malloc(sizeof(t_list));
	if (list == 0)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}
