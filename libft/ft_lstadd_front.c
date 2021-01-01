/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 23:35:41 by tilda             #+#    #+#             */
/*   Updated: 2020/11/04 17:33:33 by tilda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*new_copy;

	if (!(lst) || !(new))
		return ;
	new_copy = new;
	if (!(*lst))
	{
		*lst = new_copy;
		return ;
	}
	new_copy->next = *lst;
	*lst = new_copy;
}
