
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
