
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
