/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:04:02 by tilda             #+#    #+#             */
/*   Updated: 2020/11/04 14:24:26 by tilda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*lst_copy;

	lst_copy = lst;
	if (!(lst))
		return ;
	while (lst_copy->next)
	{
		f(lst_copy->content);
		lst_copy = lst_copy->next;
	}
	f(lst_copy->content);
}
