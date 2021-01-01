/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 23:29:24 by tilda             #+#    #+#             */
/*   Updated: 2020/11/04 17:33:02 by tilda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*end_lst;

	end_lst = lst;
	if (!(lst))
		return (NULL);
	while (end_lst->next)
	{
		end_lst = end_lst->next;
	}
	return (end_lst);
}
