/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 23:46:00 by tilda             #+#    #+#             */
/*   Updated: 2020/11/11 16:01:35 by tilda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst_copy;

	if (!(lst) || !(new))
		return ;
	lst_copy = *lst;
	if (!(lst_copy))
	{
		lst_copy = new;
		*lst = lst_copy;
	}
	else
	{
		while (lst_copy->next)
		{
			lst_copy = lst_copy->next;
		}
		lst_copy->next = new;
	}
}
